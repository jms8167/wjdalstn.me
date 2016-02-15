#!/usr/bin/perl
use strict;
use warnings;
use CGI;
my $q=new CGI;
my $ret=$q->param("aaa");
print "Content-Type: text/html; charset=utf-8";
print "\n\n";
print "<html><head></head><p>$ret</p><body></body></html>";
