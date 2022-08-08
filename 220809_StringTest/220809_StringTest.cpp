// StringTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>



std::string StringChange(const std::string& _Src, const std::string& _Old, const std::string& _New)
{

    std::string result = _Src;
    result = result.replace(result.find(_Old), _Old.length(), _New);

    return result;
}


std::vector<std::string> StringSplit(const std::string& _Src, const std::string& _Value)
{
    std::string String = _Src;

    std::vector<std::string> result;
    while (true)
    {
        size_t findNum = String.find(_Value);

        if (findNum == std::string::npos)
        {
            result.push_back(String);
            break;
        }
        result.push_back(String.substr(0, findNum));
        String.erase(0, findNum + _Value.length());

    }

    return result;
}

int main()
{


    std::string Name = StringChange("AAABBBCCC", "BBB", "DDDDX");

    std::vector<std::string> Test = StringSplit("aaafgfg,bbfffb,,aasdds,,ccc", ",,");

    // Test[0] == "aaa"
    // Test[1] == "bbb"
    // Test[2] == "ccc"

    std::cout << Name << "\n";


    for (size_t i = 0; i < Test.size(); i++)
    {
        std::cout << Test[i] << "\n";
    }



}
