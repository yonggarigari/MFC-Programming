using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSconApp01
{
    internal class Program // 수정 X
    {
        static void Main(string[] args) // Main
        {
            Console.WriteLine("*************************************************************************");
            Test test = new Test();
            test.main();
            Console.ReadKey();
        }
    }
    class Test
    {
        void func1() // char = 'int type'
        {
            char a = 'A';
            Console.WriteLine("char a = " + a);
            Console.WriteLine("char a = " + (a + 1));
            Console.WriteLine("char a = " + (a + 2));
        }
        void func2()
        {
            Console.WriteLine("int type의 크기 : " + sizeof(int) + "(byte) //범위 : " + int.MinValue + ", " + int.MaxValue);
            Console.WriteLine("char type의 크기 : " + sizeof(char) + "(byte) //범위 : " + char.MinValue + ", " + char.MaxValue);
            Console.WriteLine("long type의 크기 : " + sizeof(long) + "(byte) //범위 : " + long.MinValue + ", " + long.MaxValue);
            Console.WriteLine("double type의 크기 : " + sizeof(double) + "(byte) //범위 : " + double.MinValue + ", " + double.MaxValue);
            Console.WriteLine("float type의 크기 : " + sizeof(float) + "(byte) //범위 : " + float.MinValue + ", " + float.MaxValue);

            Console.WriteLine("(표준)int type의 크기 {0}(byte). 범위{1},{2} ", sizeof(int), int.MinValue, int.MaxValue);
            //Console.WriteLine("(표준)int type의 범위{1},{2} 크기 {0}(byte). ", sizeof(int), int.MinValue, int.MaxValue);
            Console.WriteLine($"(보간)int type의 크기 {sizeof(int)}(byte). 범위{int.MinValue},{int.MaxValue} "); // 보간문자 사용할 때는 앞에 '$'표시만 하면 됨.

        }
        void func3()
        {
            var a = 20; // var는 데이터 키워드 형태(한 번 설정된 데이터타입으로 설정됨. 중간에 수정 불가)
            Console.WriteLine($"var a = {a}");
            Console.WriteLine($"ASCII code '1' = \x31"); // ASCII code 로 출력하는 방법
            a = 10;
            Console.WriteLine($"var a = {a}");
            object o = a; // object는 데이터 타입 형태('var'와 달리 중간에 데이터 타입 변경 가능)
            Console.WriteLine($"object o = {o}");
            o = "문자열 가능";
            Console.WriteLine($"object o = {o}");
            string s = (string)o; // 명시적으로 캐스팅 해줘야 함. 이유 : object가 제일 큰 데이터 타입임. string ( object
            Console.WriteLine($"object s = {s}");
        }
        void func4() // C#은 배열도 객체
        {
            int[] arr = { 1, 2, 3 }; // 초기화 하는 법
            //int[] arr = new int[100]; // (해석)int형 배열 객체(이름 : arr) = int 타입 100개 배열 생성
          
            char[] Carr = { '안', '녕', '하', '삼' }; // 배열객체, char타입 배열은 배열 내 모든 변수를 char타입으로 설정 
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i]);
            }
            Console.WriteLine("");
            string s = new string(Carr); // string type은 오직 문자열만 다룸.
            Console.WriteLine(s);
            s = new string(Carr, 1, 2); Console.WriteLine(s);

            //for (int i = 0; i < Carr.Length; i++)
            //{
            //    Console.Write(Carr[i]);
            //}
        }
        public void main()
        {
            func1();
            func2();
            func3();
            func4();
            Console.ReadKey();
        }
    }
}
