class KaiKernel
	def pronpt
		if Process::UID.eid == 0
			return "#"
		else
			return "%"
		end
	end
	def help
		inside_funcs={
		 "help" => "Show Command List",
		 "exit" => "Exit KaiOS",
		 "cd" => "Like UNIX cd Usage:cd Directory Name"
		}
		puts "Coomand List"

		inside_funcs.each{|key,value|
			puts "\t#{key} - #{value}"
		}

		#"`ls #{$install_path}`.split("\n").each
		Dir.entries($install_path).each{|data|
			next if data == "." || data == ".."
			# Format : command - arguments and description
			desc = ""
			IO.foreach("#{$install_path}/#{data}").each{|l|
				if l =~ /DESCRIPTION/
					desc = l.split("DESCRIPTION")[1]
				end
			}
			puts "\t#{data.split(".")[0]} - #{desc}"
		}
	end
end
