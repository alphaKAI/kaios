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
			when /cd/
					unless File.exist?(line[1])
						puts "\'#{line[1]}\'という名前のディレクトリは存在しません 打ち間違えがないかご確認ください"
						return nil
					end
					Dir.chdir(line[1])
			else
				st=false
				Dir.entries($install_path).each{|data|
					next if data == "." || data == ".."
					if line[0] == data.delete(".rb")
						line.delete_at(0)
						system("ruby #{$install_path}/#{data} #{line.join(" ")}")
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
