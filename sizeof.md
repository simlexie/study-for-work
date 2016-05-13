# 程序员面试宝典整理-----预处理 、const、sizeof

标签（空格分隔）： 面试

---

## `const`用法
如果 `const`位于星号的左侧，则`const`就是用来修饰指针所指向的变量，即指针指向为常量
如果`const`位于星号的右侧，则`const`就是用来修饰指针本身，即指针本身是常量

`const`常量定义的时候必须初始化

### `const`和`define`的区别
>  `const`具有数据类型，`define`没有数据类型，编译器对前者进行类型安全检查，可是对后者只是进行替换

类里面的数据成员加上`mutable`后，修饰为`const`的成员变量就可以修改他了。

```c++
class C
{
    public:
    int incr() const
    {
        return ++m_count;
    }
    private:
    multable int m_count;
};

```

## 内联函数和宏定义

两者差别：
内联函数和普通函数相比可以加快程序的运行速度，因为不需要中断调用，在编译的时候内联函数可以直接被嵌入到目标代码中，而宏只是一个简单的替换。
内敛函数需要做参数类型检查。

inline一般只用于如下情况：
1 一个函数不断的被重复调用
2 函数只有简单的几行，且函数内不包含for，while，switch

关于宏的第一条规则是，绝不应该去使用它，除非你不得不这么做。

inline必须有与函数定义体放在一起才能是函数称为内联函数。仅将inline放在函数声明前面起不到任何作用。inline为“用于实现的关键字”，而不是“用于声明的关键字”

错误示例

    inline void f()(int x,int y)
    void f(int x, int y){}
    
正确示例

    void f(int x, int y)
    inline f(int x, int y){}

## `sizeof`用法

```c++
char *ch = "123";
char ch1[10];
char ch2[] = "123";
char *ch3 = (char*) malloc(100);
void *ch4 = (void*) malloc(100);

```
以上变量作为`sizeof`参数时，输出结果依次为：4,20,4,4,4

结构体作为`sizeof`参数时，要考虑数据对齐。

`sizeof`计算栈中分配的大小，静态变量存在全局区，若结构体中含有静态变量，则不需要计算在内。

###`sizeof`和`strlen`区别
> 1 `sizeof`是运算符，`strlen`是函数
2 `sizeof`可以用类型做参数，`strlen`只能用char*做参数，且必须以'\0'为结尾
3 当函数名作为`sizeof`的参数时不退化，但是作为`strlen`则退化为指针
4 大部分编译程序在编译的时候就把`sizeof`计算过了。这就是`sizeof(x)`可以用来定义数组维数的原因。
5 `strlen`的结果要运行的时候才能计算出来，用来计算字符串的长度，而不是类型占内存的大小
6 `sizeof`后如果是类型，则必须加括号，如果是变量名，可以不加括号。这是因为`sizeof`是个操作符而不是函数
7 `sizeof`操作符不能返回被动态分配的数组或外部的数组的尺寸


### `sizeof`的使用场合
1 `sizeof`的一个主要用途是与存储分配和I/O系统那样的例程进行通信？
2 用`sizeof`可以看出某种类型的对象在内存中所占的单元字节，例如：

    void * memset(void *s, int c,sizeof(s))

3 在动态分配一对象时，可以让系统知道要分配多少内存
4 便于一些类型的扩充，在windows中有很多结构类型就有一个专用的字段永磊存放该类型的字节大小。
5 由于操作数的字节数在实现时可能出现变化，建议在涉及操作数自己大小时用`sizeof`代替常量计算。
6 如果操作数是函数中的数组形参或函数类型的形参，`sizeof`给出其指针的大小。

### 在使用`sizeof`时需要注意的几点
1 `unsigned`影响的知识最高位bit的意义(正/负)，数据长度是不会被改变的，所以

    sizeof(unsigned int) = sizeof(int)

2 自定义类型的`sizeof`取值等同于他的类型原型
    
    typedef short WORD; sizeof(short) = sizeof(WORD)

3 对函数使用`sizeof`在编译阶段会被函数返回值的类型取代。如

    int f(){return 0;}
    sizeof(f()) = sizeof(int)

4 只要是指针，大小就是4
5 数组的大小时各维数的乘积*数组元素的大小
6 一个空类所占空间为1，单一继承的空类空间也是1，多重继承的空类空间仍是1，但是虚继承设计虚表(虚指针)，所以所占空间为4








