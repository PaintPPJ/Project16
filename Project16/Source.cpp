#include <iostream>
#include <vector>

typedef std::vector<unsigned char> Row;
const unsigned int Modulo = 7;
struct Function_nextRow_or_con
{
    unsigned char current;
    unsigned long long result;

    unsigned int inputNumRow;
    unsigned long long count;
    unsigned long long found;
};
unsigned long long nextRow(Row& row)
{
    struct Function_nextRow_or_con variebles;
    row.push_back(1);
    if (row.size() == 1)
        return 1;
  
    variebles.result = 2;

    for (size_t k = row.size() - 2; k > 0; k--)
    {
        
        variebles.current = row[k] + row[k - 1];

        if (variebles.current >= Modulo)
            variebles.current -= Modulo;

        if (variebles.current != 0)
            variebles.result++;

        row[k] = variebles.current;
    }

    return variebles.result;
}

unsigned long long countNonDivisible(unsigned int row)
{
    struct Function_nextRow_or_con variebles2;
    variebles2.result = 1;
    while (row > 0)
    {
        variebles2.result *= (row % Modulo) + 1;
        row /= Modulo;
    }
    return variebles2.result;
}

int main()
{
    struct Function_nextRow_or_con number;
    number.inputNumRow = 1000000000;
    std::cin >> number.inputNumRow;

    Row current = { 1 };


    std::vector<unsigned char> base7(12, 1); 

    number.count = 1;
    for (unsigned int row = 1; row < number.inputNumRow; row++)
    {

        base7[0]++;

        auto carryPos = 0;
        while (base7[carryPos] == Modulo + 1)
        {
            base7[carryPos] = 1;
            base7[carryPos + 1]++;
            carryPos++;
        }

        // multiply all digits
        unsigned long long found = 1;
        for (auto& x : base7)
            found *= x;

        number.count += found;
    }
    std::cout << number.count << std::endl;
    return 0;
}