#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

using namespace std;

extern string get_hash(string);
extern void print_user(string, string);
extern void change_user(string, string);
extern void delete_user(string, string);
extern void task_management(string, string);


int login()
{
    string name, Name;
    string pw, pw_in, PW_in;
    string fileData;
    string::size_type location;
    int choice2;
    bool flag_1 = false, flag_2 =false;
    int flag_3;
    char ch;  //用于获取键盘输入
    
    //while循环用于找不到用户信息时
    while(1)
    {
        system("cls");
        cout<<"Please enter your user name:";
        cin>>name;
        cout<<"Please enter the password:";
        while ((ch=_getch())!=13)  //回车键ASCII码是13
        {
            pw+=ch;
            cout<<"*";
        }
        cout<<endl;

        pw_in = get_hash(pw);
        
        if (name == "root" && pw_in == "e10adc3949ba59abbe56e057f20f883e") break; //user中无超级用户信息，故不从中查找
        else
        {
            ifstream in("users");   
            while(getline(in,fileData))
            {
                if(!fileData.compare(name)) 
                {
                    getline(in, fileData);
                    if(!fileData.compare(pw_in)) 
                    {
                        flag_1 = true; 
                        break;
                    }
                }
            }
            in.close();
            
            if (flag_1) break;
            cout<<"The user name or password is wrong! Please enter them again.\n";
            sleep(4);
        }
    }
    
    cout<<"Welcome! User "<<name<< "\n" <<endl;
    
    //while循环用于回到原界面
    while(1)
    {
        system("cls");
        if (name == "root" && pw_in == "e10adc3949ba59abbe56e057f20f883e")
        {
            cout<<"This is a super account\n";
            cout<<"Please choose the sevice you need:\n1.print account information\n2.task management\n3.print all users' information\n4.delete certain user\n5.quit\n"<<"> ";
            cin>>choice2;

            switch(choice2)
            {
                case 1: print_user(name, pw); 
                        sleep(4);
                        break;
                case 2: {
                            ofstream out("root",ofstream::app);
                            out.close();
                            task_management(name, pw); 
                            sleep(4);
                            break; 
                        }
                case 3: {
                            system("cls");
                            ifstream in("users");
                            if (!in) {cerr<<"No account existed! Please register an account first.\n"; return 0;}
                            while(getline(in, fileData))
                            {
                                cout<<fileData<<endl;
                                getline(in, fileData);
                            }
                            in.close();
                            getch();       //按下任意键返回原界面
                            break;    
                        }
                case 4: while(1)
                        {
                            system("cls");
                            cout<<"Please enter the user name of this account.\n";
                            cin>>Name;
                            //删除users中用户信息
                            ifstream in("users");  
                            if (!in) {cerr<<"No account existed! Please register an account first.\n"; return 0;}
                            ofstream out("tmp");

                            while(getline(in,fileData))//得到原文件中一行的内容
                            {
                                if (!fileData.compare(Name))//比较原文件每一行的内容和要删除的是否一致，一致就跳过
                                {
                                    getline(in,fileData);
                                    flag_2 = true;
                                    continue;
                                }
                                out<<fileData<<"\n";//不一致的内容写到中间文件中，注意换行
                            }
                            in.close();//关闭流
                            out.close();
                            
                            if (flag_2)
                            {
                                fstream outfile("users", ios::out);
                                fstream infile("tmp", ios::in);
                                while(getline(infile, fileData)) //将中间文件的内容写到原文件（覆盖）
                                {
                                    outfile<<fileData<<"\n";
                                }
                                outfile.close();//关闭流
                                infile.close();
                                
                                const char* path = "tmp";
                                remove(path);//删除tmp
                                
                                //删除用户存放任务的文件
                                const char* filePath = Name.data();
                                flag_3 = remove(filePath);

                                if (flag_3 != 0) {cout<<"fail to delete the file\n"; return 0;}
                                cout<<"account deleted successfully!\n";
                                sleep(4);
                                break;
                            }
                            else cout<<"Please enter a correct username.\n";
                            sleep(4);
                        }
                        break;
                case 5: return 1;          //返回1，跳回原函数后不挂起
                default: cout<<"Please input an integer between 1 and 5!\n";
                         sleep(4);
            }
        }
        else
        {
            cout<<"Please choose the sevice you need:\n1.print account information\n2.change account information\n3.delete this account\n4.task management\n5.quit\n"<<"> ";
            cin>>choice2;

            switch(choice2)
            {
                case 1: print_user(name, pw); break;
                case 2: change_user(name, pw); return 0;
                case 3: delete_user(name, pw); return 0;
                case 4: task_management(name, pw); break;
                case 5: return 1;          //返回1，跳回原函数后不挂起
                default: cout<<"Please input an integer between 1 and 5!\n";
            }
            sleep(4);
        }
    }
}
    