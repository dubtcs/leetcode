# 165. Compare Version Numbers 🟡

Given two version numbers, `version1` and `version2`, compare them.

Version numbers consist of one or more revisions joined by a dot `'.'`. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example `2.5.33` and `0.1` are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions `1` and `001` are considered equal. If a version number does not specify a revision at an index, then treat the revision as `0`. For example, version `1.0` is less than version `1.1` because their revision 0s are the same, but their revision 1s are `0` and `1` respectively, and `0 < 1`.

Return the following:

 - If `version1 < version2`, return `-1`.
 - If `version1 > version2`, return `1`.
 - Otherwise, return `0`.

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int c1{ 0 };
        int c2{ 0 };
        while(c1 < version1.size() || c2 < version2.size())
        {
            int v1{ 0 };
            while(c1 < version1.size())
            {
                char& c{ version1.at(c1) };
                if(c == '.')
                    break;
                v1 *= 10;
                v1 += c - '0';
                c1++;
            }

            int v2{ 0 };
            while(c2 < version2.size())
            {
                char& c{ version2.at(c2) };
                if(c == '.')
                    break;
                v2 *= 10;
                v2 += c - '0';
                c2++;
            }
            
            if(v1 < v2)
                return -1;
            if(v1 > v2)
                return 1;

            c1++;
            c2++;
        }
        return 0;
    }
};
```