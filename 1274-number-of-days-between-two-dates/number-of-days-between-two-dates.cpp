class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<std::string> v1, v2;
        istringstream ss1(date1), ss2(date2);
        std::string token;
        while (std::getline(ss1, token, '-')) v1.push_back(token);
        while (std::getline(ss2, token, '-')) v2.push_back(token);
        const char* format = "%Y-%m-%d";
        struct tm tm1, tm2;
        memset(&tm1, 0, sizeof(struct tm)); 
        memset(&tm2, 0, sizeof(struct tm)); 
        if (strptime(date1.c_str(), format, &tm1)==nullptr) {
            printf("Error : strptime for tm1\n");
            return -1;
        }
        if (strptime(date2.c_str(), format, &tm2)==nullptr) {
            printf("Error : strptime for tm2\n");
            return -1;
        }
        time_t time1 = mktime(&tm1);
        time_t time2 = mktime(&tm2);
        return (time1 > time2) ? (time1 - time2)/(3600*24) : (time2 - time1)/(3600*24);
    }
};