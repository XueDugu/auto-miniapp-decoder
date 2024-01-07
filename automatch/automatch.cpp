#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
void Print(vector< vector<int> >& record){
	int i=0;
	cout<<"temporary correct groups:"<<endl;
	for(;i<record.size();++i){
		cout<<record[i][0]<<" "<<record[i][1]<<" "<<record[i][2]<<endl;
	}
	cout<<"reinput this one(1) or give up(2),give me your answer."<<endl<<endl;
	return;
}
void FUN(int a,int b,int c,int i){
	int x1=0,x2=0,x3=0,x4=0;
	if(i<2){
		x1=1;
		x4=2;
	}
	else if(i<4){
		x2=3;
	}
	else if(i<7){
		x2=2;
		x3=1;
	}
	else if(i<9){
		x1=1;
		x2=1;
		x4=1;
	}
	else if(i<12){
		x1=2;
		x3=1;
	}
	else{
		x1=1;
		x2=2;
	}
	if(a<=4){
		--x1;
	}
	else if(a<=8){
		--x2;
	}
	else if(a<=11){
		--x3;
	}
	else{
		--x4;
	}
	if(b<=4){
		--x1;
	}
	else if(b<=8){
		--x2;
	}
	else if(b<=11){
		--x3;
	}
	else{
		--x4;
	}
	if(c<=4){
		--x1;
	}
	else if(c<=8){
		--x2;
	}
	else if(c<=11){
		--x3;
	}
	else{
		--x4;
	}
	if(x1||x2||x3||x4){
		cout<<"this is "<<i<<" group,please reinput:"<<endl;
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		FUN(aa,bb,cc,i);
	}
	return;
}
void Fill(vector< vector<int> >& table){
	vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(6);
    temp.push_back(7);
    temp.push_back(8);
    temp.push_back(10);
    temp.push_back(11);
    temp.push_back(13);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(7);
    temp.push_back(8);
    temp.push_back(11);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(8);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(9);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(7);
    temp.push_back(9);
    temp.push_back(10);
    temp.push_back(12);
    table.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(7);
    temp.push_back(8);
    temp.push_back(11);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(8);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(4);
    temp.push_back(5);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(9);
    table.push_back(temp);
    temp.clear();
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(5);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(4);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(5);
    table.push_back(temp);
    temp.clear();
    temp.push_back(4);
    table.push_back(temp);
    temp.clear();
    temp.push_back(0);
    table.push_back(temp);
    return;
}
void MATCH(){
	int i=0,a,b,c,j,choose;
	vector<int> r;
	vector< vector<int> > record;
	vector< vector<int> > table;
	Fill(table);
	cout<<"1"<<endl<<"0 -(0,1) 1 -(1,2) 2 -(2,3) 3-(3,4) 4-(4,5)"<<endl<<"2"<<endl<<"5 -(0,2) 6 -(1,3) 7 -(2,4) 8-(3,5)"<<endl<<"3"<<endl<<"9 -(0,3) 10-(1,4) 11-(2,5)"<<endl<<"4"<<endl<<"12-(0,4) 13-(1,5)"<<endl<<endl<<endl;
	for(;i<16;++i){
		choose=0;
		if(i==0){
			cout<<"input 2 1-4-4"<<endl;
		}
		else if(i==2){
			cout<<"input 2 2-2-2"<<endl;
		}
		else if(i==4){
			cout<<"input 3 2-2-3"<<endl;
		}
		else if(i==7){
			cout<<"input 2 1-2-4"<<endl;
		}
		else if(i==9){
			cout<<"input 3 1-1-3"<<endl;
		}
		else if(i==12){
			cout<<"input 4 1-2-2"<<endl;
		}
		cin>>a>>b>>c;
		while(a<0||a>13||b<0||b>13||c<0||c>13){
			cout<<"input wrong,please reinput a b c!"<<endl;
			cin>>a>>b>>c;
		}
		FUN(a,b,c,i);
		for(j=0;j<record.size();++j){
			if(find(table[record[j][0]].begin(),table[record[j][0]].end(),a)!=table[record[j][0]].end()||find(table[record[j][1]].begin(),table[record[j][1]].end(),b)!=table[record[j][1]].end()||find(table[record[j][2]].begin(),table[record[j][2]].end(),c)!=table[record[j][2]].end()){
				continue;
			}
			else{
				cout<<record[j][0]<<" "<<record[j][1]<<" "<<record[j][2]<<" don't match "<<a<<" "<<b<<" "<<c<<endl;
				Print(record);
				while(choose!=1&&choose!=2){
					cout<<"input 1 or 2"<<endl;
					cin>>choose;
				}
				break;
			}
		}
		if(choose==0){
			r.push_back(a);
			r.push_back(b);
			r.push_back(c);
			record.push_back(r);
			r.clear();
		}
		else if(choose==1){
			--i;
		}
		else if(choose==2){
			return;
		}
	}
	cout<<"Success!"<<endl;
	return;
}
int main(){
	vector< vector<int> > x144;
	string input[]={"0 13 13"};
	int inputIndex=0;
	istringstream iss(iputs[inputIndex]);
	iss>>a>>b>>c;
	++inputIndex;
	return 0;
}
