/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
	int evalRPN(vector<string> &tokens)
	{
		stack<string> s;
		int sz = tokens.size();
		int i = 0;
		while (i < sz)
		{
			if (tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-")
			{
				s.push(tokens[i]);
			}
			else
			{
				string t = s.top();
				int mul = 1;
				int muli = 1;
				int m = 0;
				int n = 0;
				int ans = 0;
				string k = "";
				int flga0 = 0;
				int flg = 0;
				int flag1 = 0;
				for (int j = t.length() - 1; j >= 0; j--)
				{
					if (t[j] == '-')
					{
						flga0 = 1;
					}
					else
					{
						m += (t[j] - 48) * mul;
						mul = mul * 10;
					}
				}

				s.pop();
				string q = s.top();
				for (int j = q.length() - 1; j >= 0; j--)
				{
					if (q[j] == '-')
					{
						flag1 = 1;
					}
					else
					{
						n += (q[j] - 48) * muli;
						muli = muli * 10;
					}
				}

				s.pop();
				if (flga0 == 1)
					m = -m;
				if (flag1 == 1)
					n = -n;

				if (tokens[i] == "*")
				{
					ans = m * n;
					s.push(to_string(ans));
				}
				else if (tokens[i] == "+")
				{
					ans = m + n;
					s.push(to_string(ans));
				}
				else if (tokens[i] == "-")
				{
					ans = n - m;
					s.push(to_string(ans));
				}
				else
				{
					ans = n / m;
					s.push(to_string(ans));
				}
			}
			i++;
		}

		string y = s.top();
		long long anss = 0;
		long long fl = 0;
		long long mu = 1;
		for (int j = y.length() - 1; j >= 0; j--)
		{
			if (y[j] == '-')
			{
				fl = 1;
			}
			else
			{
				anss += (y[j] - 48) * mu;
				mu = mu * 10;
			}
		}
		if (fl == 1)
			anss = -anss;
		return anss;
	}
};
// @lc code=end
