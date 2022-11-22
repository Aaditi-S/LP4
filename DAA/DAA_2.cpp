#include<bits/stdc++.h>
using namespace std;
class Node{
	private:
		char data;
		int freq;
		Node *lchild , *rchild;
	public:
		Node(char d , int f=-1){
			data = d;
			freq = f;
			lchild= rchild =NULL;
		}
		Node(Node *lc , Node *rc)
		{
			data = 0;
			freq = lc->freq + rc->freq;
			lchild=lc;
			rchild=rc;
		}
		void traverse(string code="")const{
			if(lchild != NULL)
			{
				lchild->traverse(code+'0');
				rchild->traverse(code+'1');
			}else{
				cout<<data<<" "<<freq<<" "<<code<<"\n";
			}
		}
		bool operator<(const Node &a)const{
			return freq>a.freq;
		}
};

void huffman_encoding(string str)
{
	vector<int>freq(256 , 0);
	priority_queue<Node>pq;
	for(int i =0 ; i<str.length() ; i++)
	{
		freq[str[i]]++;
	}
	for(int i=0 ; i<256 ; i++)
	{
		if(freq[i] > 0)
		{
			pq.push(Node(i , freq[i]));
		}
	}
	while(pq.size() > 1)
	{
		Node *lc = new Node(pq.top());
		pq.pop();
		Node *rc = new Node(pq.top());
		pq.pop();
		pq.push(Node(lc, rc));
	}
	pq.top().traverse();
}
int main()
{
	string str="";
	getline(cin , str);
	huffman_encoding(str);
}
