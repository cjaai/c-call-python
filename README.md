"# c-call-python" 

（1）新建一个VS工程<br/>
（2）选择平台为“x64”“Release”，注意此处不能选“Debug”;新建文件选择test1.c 而不是test1.cpp<br/>
（3）在VS右侧解决方案资源管理器选中工程名称右键->属性->VC++目录（注意配置平台应与运行平台一致），
在包含目录中添加“E:\Anaconda3\include”，在库目录中添加“D:\Anaconda3\libs”（你所安装Anaconda目录下的 include与libs文件夹位置），<br/>
如果要采用虚拟环境中的python应添加“E:\Anaconda3\envs\tensorflow-gpu\include”与“D:\Anaconda3\envs\tensorflow-gpu\libs”<br/>
（其中tensorflow-gpu是我取的环境名）<br/>
（4）选择链接器->输入，在“附加依赖项”中添加“D:\Anaconda3\libs\python36.lib”（你所安装Anaconda目录下的libs文件夹中相应版本的库文件）
