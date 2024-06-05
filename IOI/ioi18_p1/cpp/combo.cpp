#include "combo.h"
#include <bits/stdc++.h>

using namespace std;


string guess_sequence(int n)
{
	if (n == 1)
	{
		if (press("A") == 1)
			return "A";
 
		if (press("B") == 1)
			return "B";
 
		if (press("X") == 1)
			return "X";
 
		return "Y";
	}
 
	string s;
 
	int k = press("AB");
	if (k > 0)
	{
		if (press("A") == 1)
			s = "A";
		else
			s = "B";
	}
	else
	{
		if (press("X") == 1)
			s = "X";
		else
			s = "Y";
	}
 
	string c = "ABXY";
	c.erase(find(c.begin(), c.end(), s[0]));
 
	while (s.size() < n - 1)
	{
		string q = s + c[1] + s + c[2] + c[0] + s + c[2] + c[1] + s + c[2] + c[2];
		s += c[press(q) - s.size()];
	}
 
	if (press(s + c[0]) == n)
		s += c[0];
	else if (press(s + c[1]) == n)
		s += c[1];
	else
		s += c[2];
 
	return s;
}
