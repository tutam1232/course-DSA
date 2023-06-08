#pragma once
#include <vector>
using std::string; 
using std::vector;

struct Examinee
{
	string id;
	float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};
Examinee readExaminee(string line_info);
void printExaminee(Examinee ex);
vector<Examinee> readExamineeList(string file_name);
void writeScores(vector<Examinee> examinee_list, string out_file_name);