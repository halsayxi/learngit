# Task Management System

## 使用方法
```
./test
```
项目的编写平台是Linux，可执行文件的运行环境也是Linux，目前只有命令行操作。

**获取帮助：**
```
$ ./test -h
```
**超级用户账号和密码：**
```
User_Name: root
Password: 123456
```

**编译时请用：**
```
$ g++ -g main.cpp add_user.cpp change_user.cpp delete_user.cpp get_hash.cpp input_from_cmd.cpp login.cpp Periodic_Scanning.cpp print_user.cpp Task_Management.cpp Task_process.cpp user.h -pthread -o test
```  
**测试时请用：**
```
$ cd testfile
$ make clean
$ make
$ ./testfile
```

## 命令行操作指令说明

- **run：**  
    启动系统，进入主界面
    

- **addtask：**  
    录入新任务，用户依次输入任务名称、类型、优先度、提醒时间和开始时间


- **showtask：**  
    显示任务，用户可自由选择显示任务的范围和排序方式


- **deltask：**  
    删除任务，用户可通过输入任务id删除指定任务


- **donetask：**  
    标记已完成任务，修改任务完成状态


- **exit：**  
    退出任务管理系统


- **数字1~5：**  
    请根据界面提示输入所需功能的相应序号


## 功能详细说明
 
### 主界面

 1. **注册新用户：**
    输入新用户账号与密码即可注册成功
 
 2. **用户登录**：
    输入已注册用户账号与密码即可登录成功，进入用户界面
 
 3. **退出系统：**
    退出整个系统
 
 
### 普通用户界面（登录后）

1. **显示用户信息**：
    输入用户密码即可查看该用户账号与密码

2. **修改用户信息**：
    输入用户密码即可修改用户账号和密码

3. **删除用户信息：**
    输入用户密码即可注销当前用户

4. **任务管理：**
    进入任务管理界面

5. **退出当前界面**：
    回到主界面


### 超级用户界面（登录后）

1. **显示用户信息：**
    输入用户密码即可查看该用户账号与密码

2. **任务管理 ：**
    进入任务管理界面

3. **显示所有用户信息**：
    显示系统中已注册的所有用户账号

4. **删除指定用户：** 
    输入指定用户账号名，即可删除该用户信息

5. **退出当前界面：**
    回到主界面


### 任务管理界面（进入任务管理后）
1. **任务添加（addtask）：**
    输入命令addtask后可输入任务各个属性添加任务
    
2. **任务显示（showtask）：**
    输入命令showtask后可选择不同任务显示方式   
    
3. **任务删除（deltask）：**
    输入命令deltask后输入指定任务id可删除任务


4. **任务标记完成（donetask）：**
    输入命令donetask后输入指定任务id可将该任务标记为已完成


5. **退出当前界面（exit）：**
    回到用户界面

## 系统使用示例

### 打开系统
$./test run
  
### 登录或注册用户   

$ 1. [新用户名]--> [新用户密码]--> [再次输入新用户密码]（注册新账号）
  
$ 2. [用户名]--> [用户密码]（登录账号）
    
$ 3. （退出系统）
     
### 管理用户

1. **普通用户**

    $ 1. [用户密码] （打印账号信息）

    $ 2. [用户密码] --> [新用户名] --> [新用户密码]（修改账号信息）

    $ 3. [用户密码] （删除账号）

    $ 4.（进行任务管理）

    $ 5.（退出登录）
    
2. **超级用户**

    $ 1. [用户密码] （打印账号信息）

    $ 2. （进行任务管理）

    $ 3.  （打印所有账号）

    $ 4. [指定用户名]（删除指定账号）

    $ 5.（退出登录）
 
### 管理任务
   
$ addtask --> [任务名称] --> [任务类型] --> [任务优先级] --> [任务提醒时间] --> [任务时间]
             
    [任务名称]：任意长度字符串，以回车键结束
             
    [任务类型]：Study | Entertainment | Living
        不区分大小写
        不能为空，输入其他字符串默认为Living
             
    [任务优先级]：High | Medium | Low 
        不区分大小写
        不能为空，输入其他字符串默认为Low 

    [任务提醒时间]：格式为dd/mm[/yyyy]_[hh][:mm][:ss], [日期/月份/年份_小时:分钟:秒]
        例: 14/07/2022  表示 2022年 7月 14日
        14/07       表示 2022年 7月 14日
        14/08_12:00 表示 2022年 8月 14日 12时 00分
        14/08_12    表示 2022年 8月 14日 12时 00分
        其中 [日期/月份] 必填
        [年份]      缺省为 2022年
        [小时:分钟]  缺省为当天 08时 00分
        [分钟]      缺省设定小时的 00分
        [秒]        缺省为 00秒

    [任务时间]：时间格式同 [任务提醒时间]
                        

$ showtask --> [任务时间范围] --> [任务排列方式]

    [任务时间范围]：0 | 1 | 2
                             0：全部；1：当月；2：当天
    [任务排列方式]：0 | 1 | 2
                             0：时间；1：优先级；2：类型
   
$ deltask --> [任务id] 
             
    任务id会在“$showtask”功能中给出

$ donetask --> [任务id]
              
    任务id会在“$showtask”功能中给出
   
$ exit 

## 系统技术说明

- 自动清屏功能  

- 多线程后台提醒

- MD5密码不可逆加密

- 实现多种任务排序方式