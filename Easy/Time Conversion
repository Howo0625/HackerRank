#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int i, temp;

    if(s[8] == 'A')
    {
        if(s[0]=='1' && s[1]=='2')
        {
            s[0]='0';
            s[1]='0';
        }
        s.resize(8);
    }
    else 
    {
        temp = s[0] - '0';
        temp = temp*10 + (s[1]-'0') +12;
        if(temp == 24)
            temp = 12;
        s[0] = (char)(temp/10)+'0';
        s[1] = (char)(temp%10)+'0';
        s.resize(8);

    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
