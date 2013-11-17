#encoding:utf-8
require "find"
require "readline"
require_relative "./src/parser.rb"
require_relative "./src/kernel.rb"

=begin
	Copyleft (C) alphaKAI 2013 http://alpha-kai-net.info
	UNIX Shell Environment KaiOS in Ruby
=end
$ver = "0.0.3 rb"
$install_path = "#{Dir.pwd}/bin"
$pc_user_color = 36
class MainFunctions
	def initialize
		@parser = CommandParser.new
		@kernel = KaiKernel.new
		@shellstack = Array.new
	end
	def about
		puts "KaiOS in Ruby VERSION:#{$ver}"
		puts "Copyleft (C) alphaKAI 2013 http://alpha-kai-net.info"
		puts "実装されているコマンドの一覧はhelpコマンドで確認できます"

		@nos = RbConfig::CONFIG["target_os"]
		case @nos
			when /linux/
				@nos = "Linux"
			when /mswin(?!ce)|mingw|cygwin|bccwin/
				@nos = "Windows"
			when /darwin/
				@nos = "OS X"
			when /bsd/
				@nos = "BSD"
			else
				@nos = "Other"
		end
		puts "\n現在KaiOSが動作しているOS:#{@nos}\n\n"
	end
	def ShellLine(loop_count,error)
		path = Dir.pwd
		pcname = `hostname`.delete("\n")
		uname = ENV["USER"]

		if path =~ /\/home\/#{uname}/
			path.gsub!("/home/#{uname}","~")
		end
		unless error == 0
			print "#{error} "
		end
		
		commands = @parser.cmdlist
		tmp_ary = Array.new

		commands.each{|a|
			tmp_ary <<  a.split(".")[0]
		}
		commands = tmp_ary
		commands += Dir.entries(Dir.pwd)

		Readline.completion_proc = proc{|word|
			commands.grep(/\A#{Regexp.quote word}/)
		}
		input = Readline.readline("\r\e[#{$pc_user_color}m#{uname}@#{pcname} \e[31m[KaiOS]\e[0m \e[1m#{path}\e[0m #{@kernel.prompt}",true)

		@shellstack << input
		@parser.parser(input)
		puts ""
	end
end

i=0
error=0
@mf = MainFunctions.new
@mf.about
loop do
	error=@mf.ShellLine(i,error)
	i+=1
end
