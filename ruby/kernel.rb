class KaiKernel
	def pronpt
		if Process::UID.eid == 0
			return "#"
		else
			return "%"
		end
	end
	def help
		puts "Coomand List"
		`ls bin`.split("\n").each{|data|
			# Format : command - arguments and description
			desc = ""
			IO.foreach("bin/#{data}").each{|l|
				if l =~ /DESCRIPTION/
					desc = l.split("DESCRIPTION")[1]
				end
			}
			puts "\t#{data.split(".")[0]} - #{desc}"
		}
	end
end
