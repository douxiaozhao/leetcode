#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct SElement
{
    SElement(const string& s, int pos) : s(s), pos(pos) {}
    string s;
    int pos;
};


class HashTable
{
public:
    HashTable() : words_size(0)
    {
        for(int i = 0; i < SIZE; ++i)
        {
            table[i] = NULL;
            word_count[i] = 0;
        }
    }

    void add(const string& word, int pos)
    {
        ++words_size;
        int num = stringToInteger(word) % SIZE;
        for(int i = 0; i < SIZE; ++i)
        {
            if(table[num] == NULL)
            {
                table[num] = new SElement(word, pos);
                word_count[pos] = 1;
                return;
            }
            else
            {
                if(table[num]->s.compare(word) == 0)
                {
                    word_count[table[num]->pos]++;
                    return;
                }
                else
                {
                    num = (num+1) % SIZE;
                }
            }
        }
    }


    bool judge(const string& s, vector<string> &words, int start)
    {
        int counts = words.size();
        for(int i = 0; i < counts; ++i)
            word_temp[i] = word_count[i];

        int length = words[0].size();

        for(int i = 0; i < counts; ++i)
        {
            string word = s.substr(start+i*length, length);
            int pos= get(word);
            if(pos == -1 || --word_temp[pos] < 0)
                return false;
        }

        return true;
    }

private:
    int get(const string& word)
    {
        int num = stringToInteger(word) % SIZE;
        while(table[num] != NULL)
        {
            if(table[num]->s.compare(word) == 0)
                return table[num]->pos;
            num = (num+1) % SIZE;
        }
        return -1;
    }

    int query(const string& word)
    {
        int num = stringToInteger(word) % SIZE;
        for(int i = 0; i < SIZE; ++i)
        {
            if(table[num] == NULL)
                break;
            num = (num+1) % SIZE;
        }
        return num;
    }

    // 字符串映射成一个整数
    int stringToInteger(const string& word)
    {
        long long r = 0;
        int len =(int)(word.size());
        for(int i = 0; i < len; i++)
        {
            r = r * 10 + word[i];
            if(r > INT_MAX)
                r %= INT_MAX;
        }
        return (int)r;
    }

private:
    const static int SIZE = 9007;
    SElement* table[SIZE];
    int words_size;
    int word_count[SIZE];
    int word_temp[SIZE];
};

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> result;
    HashTable *h = new HashTable();
    int len = words.size();
    if(len == 0)
        return result;

    for(int i = 0; i < len; ++i)
        h->add(words[i], i);

    len = s.size() - words.size()*words[0].size() + 1;
    for(int i = 0; i < len; ++i)
    {
        if(h->judge(s, words, i))
            result.push_back(i);
    }
    return result;
}

int main()
{
    vector<string> words;
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    words.push_back("fooo");
    words.push_back("barr");
    words.push_back("wing");
    words.push_back("ding");
    words.push_back("wing");

    vector<int> result = findSubstring(s, words);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
