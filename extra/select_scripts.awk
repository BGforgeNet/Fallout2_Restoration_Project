# Reads .ssl paths (scripts_src/<dir>/<file>), prints those to compile: listed in scripts.lst, matched
# case-insensitively, or in global/. template/ is skipped. Usage: awk -v lst=<scripts.lst> -f select_scripts.awk
BEGIN {
	while ((getline line < lst) > 0) {
		i = index(line, " ")
		if (i > 1) listed[tolower(substr(line, 1, i - 1))] = 1
	}
}
{
	n = split($0, p, "/")
	if (p[n - 1] == "template" || tolower(p[n]) !~ /\.ssl$/) next
	compiled = p[n]
	sub(/\.ssl$/, ".int", compiled)
	if (p[n - 1] == "global" || (tolower(compiled) in listed)) print
}
