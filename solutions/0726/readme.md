# 726. Number of Atoms 🔴

Given a string `formula` representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

 - For example, `"H2O"` and `"H2O2"` are possible, but `"H1O2"` is impossible.

Two formulas are concatenated together to produce another formula.

 - For example, `"H2O2He3Mg4"` is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

 - For example, `"(H2O2)"` and `"(H2O2)3"` are formulas.
 
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than `1`), followed by the second name (in sorted order), followed by its count (if that count is more than `1`), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

## Explanation

I used different functions for contexts. A standard context is passed a map of element counts and adds to it when it finds an element. A parenthesis context is passed a map of counts, BUT it also makes a local map for the elements it counts. Once the parenthesis context breaks with a `)` closing parenthesis, it loops through and multiplies its locals before adding to the previously mentioned counts map. This way, the contexts can keep calling into eachother and multiply.

Then just sort the element names and append their counts as a string.

I used this same system in my compiler in my NAND project.

```cpp
// Messy, but it works so its fine for leetcode
class Solution {
public:
    void ParenContext(int& index, const std::string& f, std::unordered_map<std::string, int>& counts)
    {
        std::unordered_map<std::string, int> locals{};
        index++; // skip opening parenthesis
        while(index < f.size())
        {
            const char& c{ f.at(index) };
            if(c == '(')
            {
                ParenContext(index, f, locals);
            }
            else if(c == ')')
            {
                index++;
                int mult{ 0 };
                while(index < f.size())
                {
                    if(std::isdigit(f.at(index)))
                    {
                        mult *= 10;
                        mult += f.at(index++) - '0';
                    }
                    else
                        break;
                }
                if(mult == 0)
                    mult = 1;
                for(std::pair<const std::string, int>& p : locals)
                {
                    p.second *= mult;
                    counts[p.first] += p.second;
                }
                return;
            }
            else
            {
                CheckContext(index, f, locals);
            }
        }
        return;
    }
    void CheckContext(int& index, const std::string& f, std::unordered_map<std::string, int>& counts)
    {
        std::string elm{};
        int amount{ 0 };
        while(index < f.size())
        {
            const char& c{ f.at(index) };
            if(c == '(' || c == ')')
            {
                if(!elm.empty())
                    counts[elm] += (amount > 0) ? amount : 1;
                elm = "";
                amount = 0;
                if(c == '(')
                    ParenContext(index, f, counts);
                else
                    return;
            }
            else if(std::isupper(c))
            {
                if(!elm.empty())
                    counts[elm] += (amount > 0) ? amount : 1;
                amount = 0;
                elm = c;
                index++;
            }
            else if(std::islower(c))
            {
                elm += c;
                index++;
            }
            else
            {
                amount *= 10;
                amount += (c - '0');
                index++;
            }
        }
        if(!elm.empty())
            counts[elm] += (amount > 0) ? amount : 1;
    }
    string countOfAtoms(string formula) {
        std::string r{};

        int index{ 0 };
        std::unordered_map<std::string, int> counts{};
        CheckContext(index, formula, counts);

        std::vector<std::string> names{};
        for(std::pair<const std::string, int>& p : counts)
            names.push_back(p.first);
        std::sort(names.begin(), names.end());

        for(const std::string& s : names)
        {
            r += s;
            if(counts[s] > 1)
                r += std::to_string(counts[s]);
        }

        return r;
    }
};
```