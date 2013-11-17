#encoding:utf-8

=begin
	Copyleft (C) alphaKAI 2013 http://alpha-kai-net.info
	Like UNIX echo

	DevTest
=end
# DESCRIPTION Like UNIX echo Usage:echo argumaents
def echo(args)
	puts args.join(" ") 
end
echo(ARGV)
