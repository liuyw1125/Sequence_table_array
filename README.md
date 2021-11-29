##### (1)说明

​		数据结构真的太重要了，语言只是一门工具，而数据结构是内功，没有内功，招数是没有威力的。理论知识不牢靠的时候就会后悔，当年上课的时候为什么不好好听。

##### (2)使用教程

​		结合数据结构教材使用，或者b站的一些数据结构视频来使用。

##### (3)小课堂	

​		(教材选用严蔚敏、吴伟民，该书程序是伪算法。具体的程序是高一凡，西电的，大牛，只有程序。还有一本书，台湾的黄国瑜自己写的只有思路，程序是另外一个合作的清华的写的，可惜很多错的。）

​		学完数据结构之后会对面向过程的函数有一个更深的了解。

##### (4)小tip

​		clion软件在用GDB去debug的时候，怎么去监视，堆区动态数据的值呢？在点击小乌龟debug的时候，右边variables可以点击new watch添加

​			1.把指向堆区数组的指针，强制转换成二维数组的指针，再解引用

```c
	*(int(*)[10])(myseq.data)
```

​			2.这是GDB的书籍说到的方式

```c
	*myseq.data@10
```
