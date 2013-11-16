#encoding:utf-8

=begin
	Copyleft (C) alphaKAI 2013 http://alpha-kai-net.info
	Like UNIX ls

=end
# DESCRIPTION Like UNIX ls Usage: ls Directory or option option: -a :show all

def ls(arg)
	if arg[0] =~ /-.*a/
		tmp = arg[0]
		arg[0] = arg[1]
		arg[1] = tmp
	end
	arg[0] = Dir.pwd if arg[0].to_s.empty?

	Dir.entries(arg[0]).each{|dir|
		ln = false
		unless arg[1] =~ /-.*a/ 
			next if dir =~ /^\..*/
		else
			ln = true
		end
		dir += "/" if File::ftype(dir) == "directory"

		print "#{dir} "
		print "\n" if ln
	}
end
ls(ARGV)
