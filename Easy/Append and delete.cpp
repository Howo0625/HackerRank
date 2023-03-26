#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

//給兩個string + 一整數k，求s string是否可用k步調整至t string
//測資y yu 2,a aaa 5,aba aba 7

string appendAndDelete(string s, string t, int k) 
{
    int stringtag = -1,i = 0,min = 0;
    for(i=0;i<s.size();++i)
    {
        //判斷有多少相同letter
       if(s[i] != t[i]) break;
    }
    
    //計算最小移動次數
    min = s.size()- i +t.size() -i;
    
    if((s.size() + t.size()) <= k)return "Yes";//兩個string相加比k小一定可成功
    else if(min <= k)
    {
        if(i == 0) return "Yes";//若無相同letter，可用空集合無限計算
        else
        {
            if((k - min)%2 == 0) return "Yes";//一次append+一次delete需要兩步
            if(i == s.size() && i == t.size()) return "Yes";//若兩個string長的一樣可用空集合無限計算
        }
    }
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
