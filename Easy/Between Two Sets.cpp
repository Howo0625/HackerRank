#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int Se_gcd(int num1,int num2)
{
    int maxDiv = 1;  
    int i=1;
    while(i!=0&&num1-num2!=0)  
    {
        if(num1>num2)       
            i=num1-num2;
        else
            i=num2-num1;
        maxDiv = i;     
        if(num1>i)       
            num1=i;
        else
            num2=i;
    }
        return maxDiv;
}

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b) 
{
    
    int gcdb = Se_gcd(b[0],b[1]);
    //printf("%d ",gcdb);
    int abc[100],count = 0;
    for(int j=2;j<b.size();++j)
    {
        gcdb = Se_gcd(gcdb,b[j]);
    }
    //printf("%d ",gcdb);
    int k = 0;
    for(int i=1 ; i<= gcdb; i++)
    {
        if((gcdb%i)==0)
        {
            abc[k] = i;
            k++;
        }
    }
    
    for(int i=0;i<a.size();++i)
    {
        for(int j=0;j<k;j++)
        {
            if(abc[j] % a[i] != 0) abc[j] = 0;
        }
    }
    
    for(int j=0;j<k;j++)
    {
        if(abc[j] != 0) count++;
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
