---
title: Numpy（一）：numpy切片和索引
date: 2020.7.23
tags:
  - Python
  - Numpy
  - slice
  - index
abbrlink: 760d2243
---

# 背景
&emsp;NumPy(Numerical Python)是Python语言的一个扩展程序库，支持大量的维度数组与矩阵运算，此外也针对数组运算提供大量的数学函数库。NumPy 是一个运行速度非常快的数学库，主要用于数组计算。以下是numpy对多维数组进行切片和索引操作的总结。
<!--more-->

## NumPy 切片和索引
>* ndarray对象的内容可以通过索引或切片来访问和修改，与Python中list的切片操作一样。

### 实例
~~~py
import numpy as np
a = np.arange(10)
s = slice(2,7,2)   #从索引2开始到索引7停止，间隔为2
print (a[s])
#->[2  4  6]
#-----------------
import numpy as np
a = np.arange(10)  
b = a[2:7:2]   # 从索引 2 开始到索引 7 停止，间隔为 2
print(b)
#->[2  4  6]
#-----------------
import numpy as np
a = np.arange(10)  # [0 1 2 3 4 5 6 7 8 9]
b = a[5] 
print(b)
#->5
#-----------------
import numpy as np
a = np.arange(10)
print(a[2:])
#->[2  3  4  5  6  7  8  9]
#-----------------
import numpy as np
a = np.arange(10)  # [0 1 2 3 4 5 6 7 8 9]
print(a[2:5])
#->[2  3  4]
#-----------------
import numpy as np
a = np.array([[1,2,3],[3,4,5],[4,5,6]])
print(a)
# 从某个索引处开始切割
print('从数组索引 a[1:] 处开始切割')
print(a[1:])
#->
[[1 2 3]
 [3 4 5]
 [4 5 6]]
#从数组索引 a[1:] 处开始切割
[[3 4 5]
 [4 5 6]]
#------------------->
#切片还可以包括省略号 …，来使选择元组的长度与数组的维度相同。 如果在行位置使用省略号，它将返回包含行中元素的 ndarray。
import numpy as np
a = np.array([[1,2,3],[3,4,5],[4,5,6]])  
print (a[...,1])   # 第2列元素
print (a[1,...])   # 第2行元素
print (a[...,1:])  # 第2列及剩下的所有元素
#->
[2 4 5]
[3 4 5]
[[2 3]
 [4 5]
 [5 6]]
~~~
## Numpy高级索引
>* NumPy比一般的Python序列提供更多的索引方式。除了之前看到的用整数和切片的索引外，数组可以由整数数组索引、布尔索引及花式索引。

### 整数数组索引
#### 实例
~~~py
import numpy as np 
x = np.array([[1,  2],  [3,  4],  [5,  6]]) 
y = x[[0,1,2],  [0,1,0]]  
print (y)
#输出结果为：[1  4  5]

#以下实例获取了 4X3 数组中的四个角的元素。 行索引是 [0,0] 和 [3,3]，而列索引是 [0,2] 和 [0,2]。
import numpy as np 
x = np.array([[  0,  1,  2],[  3,  4,  5],[  6,  7,  8],[  9,  10,  11]])  
print ('我们的数组是：' )
print (x)
print ('\n')
rows = np.array([[0,0],[3,3]]) 
cols = np.array([[0,2],[0,2]]) 
y = x[rows,cols]  
print  ('这个数组的四个角元素是：')
print (y)
#输出结果为：
我们的数组是：
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]]
这个数组的四个角元素是：
[[ 0  2]
 [ 9 11]]

#可以借助切片 : 或 … 与索引数组组合。如下面例子：
import numpy as np
a = np.array([[1,2,3], [4,5,6],[7,8,9]])
b = a[1:3, 1:3]
c = a[1:3,[1,2]]
d = a[...,1:]
print(b)
print(c)
print(d)
#输出结果为：
[[5 6]
 [8 9]]
[[5 6]
 [8 9]]
[[2 3]
 [5 6]
 [8 9]]
~~~
### 布尔索引
>* 布尔索引通过布尔运算（如：比较运算符）来获取符合指定条件的元素的数组。
#### 实例
~~~py
import numpy as np  
x = np.array([[  0,  1,  2],[  3,  4,  5],[  6,  7,  8],[  9,  10,  11]])  
print ('我们的数组是：')
print (x)
print ('\n')
# 现在我们会打印出大于 5 的元素  
print  ('大于 5 的元素是：')
print (x[x >  5])
#输出结果为：
我们的数组是：
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]]
大于 5 的元素是：
[ 6  7  8  9 10 11]

#以下实例使用了 ~（取补运算符）来过滤 NaN。
import numpy as np 
a = np.array([np.nan,  1,2,np.nan,3,4,5])  
print (a[~np.isnan(a)])
#输出结果为：
[ 1.   2.   3.   4.   5.]

#以下实例演示如何从数组中过滤掉非复数元素。
import numpy as np 
a = np.array([1,  2+6j,  5,  3.5+5j])  
print (a[np.iscomplex(a)])
#输出如下：
[2.0+6.j  3.5+5.j]
~~~
### 花式索引
>* 花式索引指的是利用整数数组进行索引。
>* 花式索引根据索引数组的值作为目标数组的某个轴的下标来取值。对于使用一维整型数组作为索引，如果目标是一维数组，那么索引的结果就是对应位置的元素；如果目标是二维数组，那么就是对应下标的行。
>* 花式索引跟切片不一样，它总是将数据复制到新数组中。
#### 1、传入顺序索引数组
##### 实例
~~~py
import numpy as np 
x=np.arange(32).reshape((8,4))
print (x[[4,2,1,7]])
#输出结果为：
[[16 17 18 19]
 [ 8  9 10 11]
 [ 4  5  6  7]
 [28 29 30 31]]
~~~
#### 2、传入倒序索引数组
##### 实例
~~~py
import numpy as np 
x=np.arange(32).reshape((8,4))
print (x[[-4,-2,-1,-7]])
#输出结果为：
[[16 17 18 19]
 [24 25 26 27]
 [28 29 30 31]
 [ 4  5  6  7]]
~~~
#### 3、传入多个索引数组（要使用np.ix_）
##### 实例
~~~py
import numpy as np 
x=np.arange(32).reshape((8,4))
print (x[np.ix_([1,5,7,2],[0,3,1,2])])
#输出结果为：
[[ 4  7  5  6]
 [20 23 21 22]
 [28 31 29 30]
 [ 8 11  9 10]]
#---------------------
#x[np.ix_([1,5,7,2],[0,3,1,2])]这句话会输出一个4*4的矩阵，其中的元素分别是：
x[1,0] x[1,3] x[1,1] x[1,2]
x[5,0] x[5,3] x[5,1] x[5,2]
x[7,0] x[7,3] x[7,1] x[7,2]
x[2,0] x[2,3] x[2,1] x[2,2]
#相当于：
y=np.array([[x[1,0], x[1,3], x[1,1], x[1,2]],\
            [x[5,0], x[5,3], x[5,1],x[5,2]],\
            [x[7,0] ,x[7,3], x[7,1], x[7,2]],\
            [x[2,0], x[2,3], x[2,1], x[2,2]]])
#如果 np.xi_ 中输入两个列表，则第一个列表存的是待提取元素的行标，第二个列表存的是待提取元素的列标.
#第一个列表中的每个元素都会遍历第二个列表中的每个值，构成新矩阵的一行元素。
~~~