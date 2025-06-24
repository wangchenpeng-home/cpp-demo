#include <iostream>
#define MAX 1000
using namespace std;

void ShowMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、推出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

struct contact
{
    string name;
    int sex;
    string phonenumber;
};

struct contacts
{
    contact contacts[MAX];
    int number;//通讯录人数
};

void addContact(contacts &person)
{
    if(person.number == MAX)
    {
        cout << "通讯录已满,无法添加。\n";
    }
    else
    {
        //添加姓名
        string addname;
        cout << "请输入姓名：";
        cin >> addname;
        person.contacts[person.number].name = addname;
        //添加电话号码
        string phone;
        cout << "请输入电话号码：";
        cin >> phone;
        person.contacts[person.number].phonenumber = phone;
        //添加性别
        int sex;
        while(true)
        {
            cout << "请输入性别（男1or女0）:";
            cin >> sex;
            if(sex == 1 || sex == 0)
            {
                person.contacts[person.number].sex = sex;
                break;
            }
            else
                cout << "请输入正确性别：";
        }

        person.number++;
    }
}

void showContact(contacts person)
{
    if(person.number == 0)
    {
        cout << "联系人为空\n";
    }
    else
    {
        for(int i = 0; i < person.number; i++)
        {
            cout << "姓名： " << person.contacts[i].name;
            string p_sex;
            if(person.contacts[i].sex == 1)
            {
                p_sex = "男";
            }
            else
            {
                p_sex = "女";
            }
            cout << "     性别:  " << p_sex;

            cout << "     电话:  " << person.contacts[i].phonenumber << endl;
        }
    }
}

int IsExist(contacts person, string p_name)//判断联系人是否存在
{
    if(person.number == 0)
    {
        cout << "联系人为空\n";
    }
    else
    {
        for(int i = 0; i < person.number; i++)
        {
            if(p_name == person.contacts[i].name)
                return i;
        }
        return -1;
    }
    return -1;
}

void DeleteContact(contacts &person)//删除联系人
{
    cout << "Pleas input a contact name you want to delete : \n";
    string p_name;
    cin >> p_name;
    if(IsExist(person, p_name) != -1)
    {
        int ret = IsExist(person, p_name);
        for(; ret < person.number; ret++)
        {
            person.contacts[ret] = person.contacts[ret+1];
            person.number--;
            cout << "删除成功！\n";
        }
    }
    else
    {
        cout << "查无此人！\n删除失败！\n";
    }

}

void FindContact(contacts person)//查找
{
    cout << "Pleas input a contact name you want to find : \n";
    string p_name;
    cin >> p_name;
    int ret = IsExist(person, p_name);
    if(ret != -1)
    {
        cout << "姓名 ：" << person.contacts[ret].name << endl;
        string p_sex;
            if(person.contacts[ret].sex == 1)
            {
                p_sex = "男";
            }
            else
            {
                p_sex = "女";
            }
        cout << "     性别:  " << p_sex;
        cout << "电话 ：" << person.contacts[ret].phonenumber << endl;
    }
    else
    {
        cout << "查无此人！\n查找失败！\n";
    }
}

void ModifyContact(contacts &person)//修改
{
    cout << "Pleas input a contact name you want to modify : \n";
    string p_name;
    cin >> p_name;

    int ret = IsExist(person, p_name);

    if(ret != -1)
    {
        string phone;
        cout << "Pleas updata the contact phone number: \n";
        cin >> phone;
        person.contacts[ret].phonenumber = phone;

        int sex;
        cout << "Pleas updata the contact sex(1--man or 0--woman): \n";
        cin >> sex;
        person.contacts[ret].sex = sex;
    }
    else
    {
        cout << "查无此人!\n";
    }

}

void ClearContacts(contacts &person)//清空
{
    person.number = 0;
}

int main()
{
    contacts person;
    person.number =0;
    //初始化;

    int slec = 0, slec1 = 0;

    while(1)
    {
        ShowMenu();

        cin >> slec;

        switch(slec)
        {
        case 1://添加联系人
            addContact(person);
            break;
        case 2://显示联系人
            showContact(person);
            break;
        case 3://删除联系人
            DeleteContact(person);
            break;
        case 4://查找联系人
            FindContact(person);
            break;
        case 5://修改联系人
            ModifyContact(person);
            break;
        case 6://清空通讯录
            ClearContacts(person);
            break;
        case 0:
            cout << "欢迎下次使用！\n";
            return 0;
            break;
        default:
            break;
        }

        cout << "继续请按1:\n";

        cin >> slec1;

        switch(slec1)
        {
        case 1:
            system("cls");
            break;
        default:
            return 0;
            break;
        }

    }

    return 0;
}
