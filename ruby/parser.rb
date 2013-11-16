class CommandParser
	def initialize
		@kernel=KaiKernel.new
	end
	def parser(cmdstr)
		line = cmdstr.split(" ")
		
		case line[0]
			when /help/
				@kernel.help
			when /exit/
				@kernel.exit
			else
				st=false
				`ls bin`.split("\n").each{|data|
					if line[0] == data.delete(".rb")
						line.delete_at(0)
						system("ruby bin/#{data} #{line.join(" ")}")
						st=true
						break
					end
				}
				unless st
					puts "\'#{line[0]}\'はKaiOSに対して有効なコマンドではありません" unless line[0].to_s.empty?
				end
		end
	end
end
