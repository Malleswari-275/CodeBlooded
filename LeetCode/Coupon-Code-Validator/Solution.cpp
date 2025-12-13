1class Solution {
2public:
3    vector<string> validateCoupons(vector<string>& code,
4                                   vector<string>& businessLine,
5                                   vector<bool>& isActive) {
6
7        vector<string> electronics, grocery, pharmacy, restaurant;
8
9        for (int i = 0; i < code.size(); i++) {
10
11            // 1. Empty check
12            if (code[i].empty()) continue;
13
14            // 2. Character validation
15            bool valid = true;
16            for (char ch : code[i]) {
17                if (!isalnum(ch) && ch != '_') {
18                    valid = false;
19                    break;
20                }
21            }
22            if (!valid || !isActive[i]) continue;
23
24            // 3. Bucket by business line
25            if (businessLine[i] == "electronics")
26                electronics.push_back(code[i]);
27            else if (businessLine[i] == "grocery")
28                grocery.push_back(code[i]);
29            else if (businessLine[i] == "pharmacy")
30                pharmacy.push_back(code[i]);
31            else if (businessLine[i] == "restaurant")
32                restaurant.push_back(code[i]);
33        }
34
35        // 4. Sort each bucket
36        sort(electronics.begin(), electronics.end());
37        sort(grocery.begin(), grocery.end());
38        sort(pharmacy.begin(), pharmacy.end());
39        sort(restaurant.begin(), restaurant.end());
40
41        // 5. Merge in required order
42        vector<string> result;
43        result.insert(result.end(), electronics.begin(), electronics.end());
44        result.insert(result.end(), grocery.begin(), grocery.end());
45        result.insert(result.end(), pharmacy.begin(), pharmacy.end());
46        result.insert(result.end(), restaurant.begin(), restaurant.end());
47
48        return result;
49    }
50};
51