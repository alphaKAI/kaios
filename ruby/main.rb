#encoding:utf-8
require "find"
require_relative "./src/parser.rb"
require_relative "./src/kernel.rb"

=begin
	Copyleft (C) alphaKAI 2013 http://alpha-kai-net.info
	UNIX Shell Environment KaiOS in Ruby
=end
$ver = "0.0.2 rb"
$install_path = "#{Dir.pwd}/bin"
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
		pcname = File.read("/etc/hostname")
		uname = ENV["USER"]
		
		pcname[pcname.size-1] = "\0"

		unless error == 0
			print "#{error} "
		end

		print "\r#{uname}@#{pcname} #{path} #{@kernel.pronpt()} "

		input = STDIN.gets.chomp
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
