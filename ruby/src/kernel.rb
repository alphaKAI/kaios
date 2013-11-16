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
		 "cd" => "Like UNIX cd Usage:cd Directory Name",
		 "date" => "Show now date. You can change format. Usage: date option[format]"
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
	def exit
		puts "ByeBye :-)"
	end
	def date(format = "%Y年 %m月 %d日 %A曜日 %H:%M:%S %Z")
		date_ = {
			"Sunday" => "日",
			"Monday" => "月",
			"Tuesday" => "火",
			"Wednesday" => "水",
			"Thursday" => "木",
			"Friday" => "金",
			"Saturday" => "土"
		}
		format = format.gsub(/(%A|%a)/,date_[Time.now.strftime("%A")])

		puts Time.now.strftime(format)
	end
end
