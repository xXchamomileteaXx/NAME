#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <string.h>
#include <algorithm>
#include <cctype>
// для проверки используйте английский язык

using namespace std;

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void prob(string& str)
{
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == ' ')
        {
            while (str[j + 1] == ' ')
                str.erase(j + 1, 1);
        }
    }
    if (str[0] == ' ')
        str.erase(0, 1);

    if (str[str.length() - 2] == ' ')
        str.erase(str.length() - 2, 1);

}


void edit(string &str)
{
    string strbuf;
    char zn[9] = { ',' , ':' , ';' , '!' , '?' , '-' , '"' };
    strbuf = str;

    cout << "Not edited text: " << strbuf << "\n\n";

    // убирает повторяющиеся пробелы
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == ' ')
        {
            while (str[j + 1] == ' ')
                str.erase(j + 1, 1);
        }
    }
    if (str[0] == ' ')
        str.erase(0, 1);

    if (str[str.length() - 2] == ' ')
        str.erase(str.length() - 2, 1);

    // удаляет знаки припинания кроме точек
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (str[i] == zn[j])
            {
                while (str[i + 1] == zn[j])
                    str.erase(i + 1, 1);
            }
        }

    }

    // убирает повторяющиеся точки, кроме <...>
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == '.' && str[j + 1] == '.' && str[j + 2] == '.')
        {
            j += 2;
        }
        else
            if (str[j] == '.')
            {
                while (str[j + 1] == '.')
                    str.erase(j + 1, 1);
            }
    }

    // понижение регистра
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    cout << "Edited text: " << str;
}
void again(string str)
{
    int pos_3 = 0, chek_ = 0;
    string strfw = str,sf;
    cout << "String: "<< str << "\n\n";
    for (int i = 0; i < strfw.length(); i++)
    {

        if (strfw[i] == ' ')
        {
            sf = strfw.substr(0, i);
            strfw.erase(0, ++i);
            i = 0;

            for (int k = 0; k < sf.length(); k++)
            {
                if (sf[k] == sf[0])
                    pos_3++;
            }
            if (pos_3 > 1)
            {
                cout << "\nfound word: ";
                SetColor(14, 0);
                cout << sf << endl;
                chek_++;
                SetColor(7, 0);
            }
            pos_3 = 0;
        }

        if (strfw[i] == '.')
        {
            if (i == strfw.length() - 1)
            {
                sf = strfw.substr(0, i);
                strfw.erase(0, ++i);
                i = 0;

                for (int k = 0; k < sf.length(); k++)
                {
                    if (sf[k] == sf[0])
                        pos_3++;
                }
                if (pos_3 > 1)
                {
                    cout << "\nfound word: ";
                    SetColor(14, 0);
                    cout << sf << endl;
                    chek_++;
                    SetColor(7, 0);
                }
                pos_3 = 0;

            }
        }
    }

    if (chek_ == 0)
        cout << "Rezult: words is not found";
}
void delet(string str)
{

    string serch, str_3;
    int pos_4 = 0;
   
    cout << "Enter a set of letters and / or numbers: ";
    cin.ignore();
    getline(cin, serch);
    str_3 = str;
    pos_4 = str_3.find(serch);
    while (pos_4 != string::npos)
    {
        str_3.erase(pos_4, serch.length() + 1);
        pos_4 = str_3.find(serch, pos_4 + 1);
    }
    cout << "\nString: " << str;
    cout << "\n\nString after removal: " << str_3 << endl;
}
void serL(string str,string strsbp)
{
    string strp;
    int k = 0; int sl = 0;

    strp = str;
    
    for (int i = 0; i < strp.length(); i++)
    {
        int j = 0;
        k++;

        while ((j < strsbp.length()) && (strsbp[j] == strp[i + j]))
        {

            j = j + 1;

        }
        if (j == strsbp.length())
        {
            for (int l = sl; l < i; l++)
            {
                cout << strp[l];
                sl++;
            }

            SetColor(14, 0);
            for (int l = sl; l < i + j ; l++)
            {
                cout << strp[l];
                sl++;
            }
            SetColor(7, 0);

        }
        else
        {
            for (int l = sl; l < i ; l++)
            {
                cout << strp[l];
                sl++;
            }
        }

    }

}
void serKMP(string str, string strsbp)
{
    string strbuf;
    strbuf = str;
    int l = 0, i, j, strlen, strsbplen, chek = 0;
    while (l != -1)
    {

        strlen = str.length();
        strsbplen = strsbp.length();
        int d[550];
        // Вычисление префикс-функции
        i = 0;
        j = -1;
        d[0] = -1;
        while (i < strsbplen - 1)
        {
            while ((j >= 0) && (strsbp[j] != strsbp[i]))
                j = d[j];
            ++i;
            ++j;
            d[i] = (strsbp[i] == strsbp[j]) ? d[j] : j;
        }
        // Поиск строки
        for (i = 0, j = 0; (i <= strlen - 1) && (j <= strsbplen - 1); ++i, ++j)
            while ((j >= 0) && (strsbp[j] != str[i]))
                j = d[j];

        l = (j == strsbplen) ? i - j : -1;

        for (i = 0; i < l; i++)
            cout << str[i];
        SetColor(14, 0);
        for (i = l; i < l + strsbp.length(); i++)
        {
            chek++;
            cout << str[i];
        }
        SetColor(7, 0);
        if(l != - 1)
        str.erase(0, l + strsbp.length() );
    }    
    for (int i = 0; i < str.length() - 1; i++)
        cout << str[i];
}

int main()
{
  string str,strch,strb,strbuf,strbuf_,strsbp;
  string file; ifstream fin;
  int task,task_1,stch = 0, stch2 = 0;

  cout << "Select 1 to enter through file,2 from the keyboard\n\n" << "You entered: ";
  cin >> task_1;
    
  if (task_1 == 1)
  {
  begin_1:
      cout << "\nEnter a file name: ";
      cin.ignore();
      getline(cin, file);
      fin.open(file);

      if (!fin.is_open())
      {
          cout << "\nFile opening error";
      }
      else
      {
          while (!fin.eof())
          {
              str = "";
              getline(fin, str);
              cout << "\nstring: " << str << endl;
          }
      }
      fin.close();

      strbuf = str;
      prob(str);

      for (int i = 0; i < str.length(); i++)
      {
          if (str[i] != ' ')
              stch++;
          if (stch > 10)
          {
              stch = 0;
              cout << "\nWord has more than ten letters,enter again\n\n";
              system("pause"); system("cls");
              goto begin_1;
          }

          if (str[i] == ' ')
              stch = 0;
      }
      for (int i = 0; i < str.length(); i++)
      {
          if (str[i] == ' ')
              stch2++;
          if (stch2 > 51)
          {
              stch2 = 0;
              cout << "\nYou entered more than fifty words,enter again\n\n";
              system("pause"); system("cls");
              goto begin_1;
          }
      }
      if (str[str.length() - 1] != '.')
      {
          cout << "\nThere is no dot at the end of the sentence,enter again\n\n";
          system("pause"); system("cls");
          goto begin_1;
      }
  }else
      if (task_1 == 2)
      {

      begin_2:         
          cout << "\nEnter string: ";
          cin.ignore();
          getline(cin, str);
          strbuf = str;
          prob(str);

          for (int i = 0; i < str.length(); i++)
          {
              if (str[i] != ' ')
                  stch++;
              if (stch > 10)
              {
                  stch = 0;
                  cout << "\nWord has more than ten letters,enter again\n\n";
                  system("pause"); system("cls");
                  goto begin_2;
              }

              if (str[i] == ' ')
                  stch = 0;
          }

          for (int i = 0; i < str.length(); i++)
          {
              if (str[i] == ' ')
                  stch2++;
              if (stch2 > 51)
              {
                  stch2 = 0;
                  cout << "\nYou entered more than fifty words,enter again\n\n";
                  system("pause"); system("cls");
                  goto begin_2;
              }
          }

          if (str[str.length() - 1] != '.')
          {
              cout << "\nThere is no dot at the end of the sentence,enter again\n\n";
              system("pause"); system("cls");
              goto begin_2;
          }
      }
 
  cin.sync();
  system("cls");

  do
  {
      cout << "Enter number of task\n\n";
      cout << "(1) Print the edited text\n\n";
      cout << "(2) Print words in which the first letter of the word occurs in this word again\n\n";
      cout << "(3) Print the same sequence by removing the specified set of letters and / or numbers from all words\n\n";
      cout << "(4) Find the substring that was entered by the user in the existing string\n\n";
      cout << "(0)exit";
      cout << "\n\nYou entered: ";
      
      cin >> task;
      cout << " ";
      
      system("cls");
 
      switch (task)
      {

      case 1:

          edit(str);

          cout << "\n\n";
          system("pause"); system("cls");
          break;

      case 2:

          again(str);

          cout << "\n\n";
          system("pause"); system("cls");
          break;

      case 3:
          
          delet(str);

          cout << "\n\n";
          system("pause"); system("cls");
          break;

      case 4:
          strbuf_ = str;
          cout << "\nEnter string you want find(found word will be yellow): ";
          cin.ignore();
          getline(cin, strsbp);

          cout << "\nLinear search: ";
          serL(str,strsbp); cout << ".";

          cout << "\n\nKNM search: ";
          serKMP(strbuf_, strsbp); cout << ".";

          cout << "\n\n";
          system("pause"); system("cls");
          break;
      }
        
  } while (task != 0);
  return 0;
}

