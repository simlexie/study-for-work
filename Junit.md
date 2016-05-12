# Junit

标签（空格分隔）： 测试

---
部分转自 【转载请注明—作者：Java我人生（陈磊兴）  [原文出处][1]】

### 安装步骤：
####导入三个jar包
  [junit-4.12.jar][2]
  [hamcrest-library-1.3.rc2.jar][3]
  [hamcrest-core-1.3.rc2.jar][4]
 
  导入方法如下：  
![导入方法如下][5]
---
### 新建测试用例
右击包名，点击新建，或者新建里的others，选择JUnit test case，如下图所示：
![此处输入图片的描述][6]

  接下来，给测试类起名字和选择要测试的类，如下图所示：
  ![此处输入图片的描述][7]

  然后点击【Next】，选择要被测试类中的测试方法，如下图所示：
  ![此处输入图片的描述][8]

  最后新建完成，如下（第一个方法是生成的方法，后边几个都是我自己手动写上去的）：
```java
package JUnitTest;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Ignore;
import org.junit.Test;

public class TestJava {

	@Test
	public void testMain() {
		fail("Not yet implemented");
	}

	@Test
	public void testTest() {
		System.out.println("@Test");//调用自己要测试的方法
	}
	
	@Test
	public void testAssert() {
		assertEquals("chenleixing","chenlei");
	}
	
	@Test(timeout=1)
	public void testTimeout() {
		System.out.println("超时测试");
	}

	@Before
	public void testBefore(){
		System.out.println("@Before");
	}
	
	@BeforeClass
	public static void testBeforeClass(){//必须为静态方法
		System.out.println("@BeforeClass");
	}
	
	@After
	public void testAfter(){
		System.out.println("@After");
	}
	
	@AfterClass
	public static void testAfterClass(){//必须为静态方法
		System.out.println("@AfterClass");
	}
	
	@Ignore
	public void testIgnore(){
		System.out.println("@Ignore");
	}
}

```

####JUnit4注解解释

> 1. @Test : 测试方法，测试程序会运行的方法，后边可以跟参数代表不同的测试，如(expected=XXException.class) 异常测试，(timeout=xxx)超时测试
2. @Ignore : 被忽略的测试方法
3. @Before: 每一个测试方法之前运行
4. @After : 每一个测试方法之后运行
5. @BeforeClass: 所有测试开始之前运行
6. @AfterClass: 所有测试结束之后运行
fail方法是指测试失败
assertEquals测试2个参数是否相等，具体[参考相应API][9]

####运行测试用例
把自己的测试代码写在@Test注解后者其他注解的方法里边，点击运行新建的测试用例，结果如下：
![此处输入图片的描述][10]

带差号的是说明测试失败的，testMain()和testAssert()肯定会失败，对号的是测试成功的。
控制台输出的结果如下：

```java
<span style="font-size:18px;">@BeforeClass
@Before
超时测试
@After
@Before
@After
@Before
@Test
@After
@Before
@After
@AfterClass</span>
```
更多参考[JUnit4高级篇-由浅入深][11]


  [1]: http://blog.csdn.net/chenleixing/article/details/44259453
  [2]: http://download.csdn.net/download/chenleixing/8499937
  [3]: http://download.csdn.net/download/chenleixing/8499941
  [4]: http://download.csdn.net/download/chenleixing/8499949
  [5]: http://img.blog.csdn.net/20150314150502958?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvY2hlbmxlaXhpbmc=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center
  [6]: http://img.blog.csdn.net/20150314151240334?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvY2hlbmxlaXhpbmc=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center
  [7]: http://img.blog.csdn.net/20150314151643157?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvY2hlbmxlaXhpbmc=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center
  [8]: http://img.blog.csdn.net/20150314151911578?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvY2hlbmxlaXhpbmc=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center
  [9]: http://download.csdn.net/download/chenleixing/8499929
  [10]: http://img.blog.csdn.net/20150314154406563?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvY2hlbmxlaXhpbmc=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center
  [11]: http://blog.csdn.net/chenleixing/article/details/44260359