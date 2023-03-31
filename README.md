# JVM(JDK Version Management)

## 介绍

jdk 版本管理工具

适用系统：Windows

配置文件：jvs

```
[name]-[path]

17-D:/java/jdk-17
8-D:/java/jdk-8
```

## 使用

1. 配置环境变量`JVM_HOME`的值为jvm.exe所在目录

2. 将`JVM_HOME`添加到path

3. 在`JVM_HOME`目录下新建并编写jvs文件

4. ```powershell
   # 以管理员方式运行
   jvm [name]
   ```

   