//1. 认识引用
void test01(){

	int a = 10;
	//给变量a取一个别名b
	int& b = a;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "------------" << endl;
	//操作b就相当于操作a本身
	b = 100;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "------------" << endl;
	//一个变量可以有n个别名
	int& c = a;
	c = 200;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	cout << "------------" << endl;
	//a,b,c的地址都是相同的
	cout << "a:" << &a << endl;
	cout << "b:" << &b << endl;
	cout << "c:" << &c << endl;
}
//2. 使用引用注意事项
void test02(){
	//1) 引用必须初始化
	//int& ref; //报错:必须初始化引用
	//2) 引用一旦初始化，不能改变引用
	int a = 10;
	int b = 20;
	int& ref = a;
	ref = b; //不能改变引用
}

//1. 建立数组引用方法一
typedef int ArrRef[10];
int arr[10];
ArrRef& aRef = arr;
for (int i = 0; i < 10;i ++){
    aRef[i] = i+1;
}
for (int i = 0; i < 10;i++){
    cout << arr[i] << " ";
}
cout << endl;
//2. 建立数组引用方法二
int(&f)[10] = arr;
for (int i = 0; i < 10; i++){
    f[i] = i+10;
}
for (int i = 0; i < 10; i++){
    cout << arr[i] << " ";
}
cout << endl;

Type& ref = val; // Type* const ref = &val;

//发现是引用，转换为 int* const ref = &a;
void testFunc(int& ref){
	ref = 100; // ref是引用，转换为*ref = 100
}
int main(){
	int a = 10;
	int& aRef = a; //自动转换为int* const aRef = &a;这也能说明引用为什么必须初始化
	aRef = 20; //内部发现aRef是引用，自动帮我们转换为: *aRef = 20;
	cout << "a:" << a << endl;
	cout << "aRef:" << aRef << endl;
    testFunc(a);
	return EXIT_SUCCESS;
} 

