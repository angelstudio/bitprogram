#include <iostream>
#include <windows.h>
using namespace std;
 
const unsigned char s=3; // �ĵ�ͼ��
const unsigned char smile=1; // ����΢Ц
int main()
{
  SetConsoleOutputCP(437); // ���û���Ϊ����ϵͳ
  system("color 0c"); // ����Ϊ��ɫ,�Ե�������ܰ��
   
  cout<<"\n\nDarling:Merry Christrmas\n\n";
  int row,col,sty,sty2,i=0;
  int love[5]={1,3,5,3,1};
  // ��ӡ����
  for (row=1;row<=5;row++) // ��������
  {
      if(i<=2){
          for(sty=3;sty>=row;sty--) // �������
              cout<<"  ";
          for(col=love[i];col>=1;col--) // ��������
              cout<<s<<" ";
      }
      else if(i>=3){
          for (sty2=8%row?3:2;sty2>=1;sty2--) // ԭ��ͬ��
              cout<<"  ";
          for (col=love[i];col>=1;col--)   // ԭ��ͬ��
              cout<<s<<" ";
      }
       
      cout<<endl;
      i++;
    }
   cout<<"\n\n  Darling:I LOVE YOU.521"<<smile<<smile<<s<<endl;
   system("pause"); // ����Ļ��ͣ,�������������˶࿴��
}
