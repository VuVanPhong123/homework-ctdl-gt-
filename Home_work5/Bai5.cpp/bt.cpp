#include<bits/stdc++.h>
using namespace std;
class Student{
    private: string name;
    private: string group;
    public: Student(){}
    public: Student(string na,string gr){
        name=na;
        group=gr;
    }
    public: string getName(){
        return name;
    }
    public: string getGroup(){
        return group;
    }
};
int main(){
    map<int,Student*> stulist;
    while (true){

        string s;
        cin>>s;
        stringstream ss(s);
        char a;
        int k;
        string na;
        string  gr;
        int check =0;
        if (s[2]=='s'){
            while (true){
                ss>>a;
                if (a=='('){
                        ss>>k;
                    }
                if (a==','&&check==0){
                    while (true){
                        ss>>a;
                        if (a==','){
                            break;
                        }
                        na+=a;
                    }
                    check++;
                }
                if (a==','&&check==1){
                    while (true){
                        ss>>a;
                        if (a==')')
                            break;
                        gr+=a;
                    }
                    check=0;
                    break;
                }
            }
            Student* stu=new Student(na,gr);
            na="";
            gr="";
            stulist.insert({k,stu});
        }
        if (s[2]=='f'){
            while (true){
                ss>>a;
                if (a=='('){
                    ss>>k;
                    if (stulist.find(k)==stulist.end())
                        cout<<"NA,NA"<<endl;
                    else {
                        cout<<stulist[k]->getName()<<","<<stulist[k]->getGroup();
                    }
                    break;
                }
            }
        }
        if (s[1]=='e'){
            while (true){
                ss>>a;
                if (a=='('){
                    ss>>k;
                    delete(stulist[k]);
                    stulist.erase(k);
                    break;
                }
            }
        }

    }
}
