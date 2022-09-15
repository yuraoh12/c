#include <iostream>
#include <fstream>
#include <cstdlib>
#include <document.h>
#include <istreamwrapper.h>
#include <writer.h>
#include <ostreamwrapper.h>
#include <prettywriter.h>
#include <vector>
#include <map>
#include <sstream>
#include <io.h>

using namespace std;
using namespace rapidjson;

const string ENV[24] = {
   "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
   "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
   "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
   "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
   "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
   "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
   "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
   "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
   "SERVER_SIGNATURE","SERVER_SOFTWARE" };

vector<string> split(string str, char deli) {
	vector<string> internal;
	stringstream ss(str);
	string tmp;

	while (getline(ss, tmp, deli)) {
		internal.push_back(tmp);
	}

	return internal;
}

string get_server(string key) {
	const char* val = getenv(key.c_str());

	if (val == NULL) {
		return "";
	}
	else {
		string s(val);
		return s;
	}
}

string get_param(string key) {
	string s = get_server("QUERY_STRING");

	vector<string> s2 = split(s, '&');
	map<string, string> paramMap;

	for (int i = 0; i < s2.size(); i++) {
		vector<string> s3 = split(s2.at(i), '=');
		paramMap.insert(make_pair(s3[0], s3[1]));
	}

	return paramMap[key];
}

void make_article_to_jsonfile(map<string, string> article) {
	StringBuffer s;
	PrettyWriter<StringBuffer> writer(s);

	writer.StartObject();

	writer.Key("id");
	writer.String(article["id"].c_str());
	writer.Key("title");
	writer.String(article["title"].c_str());
	writer.Key("body");
	writer.String(article["body"].c_str());

	writer.EndObject();

	string file_path = R"(C:\Test\article_)" + article["id"] + ".json";

	std::ofstream of(file_path);
	of << s.GetString();
	of.close();
}

map<string, string> make_jsonfile_to_article(string file_path) {
	std::ifstream ifs{ file_path };

	if (!ifs.is_open())
	{
		std::cerr << "Could not open file for reading!\n";
		throw std::runtime_error("Can't read the JSON string to the file!");
	}


	IStreamWrapper isw{ ifs };

	Document doc{};
	doc.ParseStream(isw);

	StringBuffer buffer{};
	Writer<StringBuffer> writer2{ buffer };
	doc.Accept(writer2);

	if (doc.HasParseError())
	{
		std::cout << "Error  : " << doc.GetParseError() << '\n'
			<< "Offset : " << doc.GetErrorOffset() << '\n';
		throw std::runtime_error("Can't read the JSON string to the file!");
	}

	const std::string jsonStr{ buffer.GetString() };

	doc.Parse(jsonStr.c_str());

	map<string, string> article;

	article["id"] = doc["id"].GetString();
	article["title"] = doc["title"].GetString();
	article["body"] = doc["body"].GetString();

	return article;
}

vector<string> get_file_names(string folder_path) {
	_finddata_t fd;
	long handle;
	int result = 1;
	folder_path += "*.json";
	handle = _findfirst(folder_path.c_str(), &fd);

	vector<string> file_names{};
	if (handle == -1)
	{
		return file_names;
	}
	while (result != -1)
	{
		file_names.push_back(fd.name);
		result = _findnext(handle, &fd);
	}
	_findclose(handle);

	return file_names;
}

void delete_json_file(string target_file) {
	string file_root = R"(C:\Test\)";
	string target_path = file_root + target_file;

	remove(target_path.c_str());
}

vector<map<string, string>> get_all_articles() {
	vector<string> file_names = get_file_names(R"(C:\Test\)");

	vector<map<string, string>> articles{};

	for (auto fn : file_names) {
		string file_path = R"(C:\Test\)" + fn;
		map<string, string> article = make_jsonfile_to_article(file_path);

		articles.push_back(article);
	}

	return articles;
}

int main() {
	cout << "Content-type:text/html\r\n\r\n";

	string action = get_param("action");
	vector<map<string, string>> articles{};

	if (!action.empty()) {
		if (action == "list") {
			articles = get_all_articles();
			for (auto a : articles) {
				cout << "번호 : " << a["id"] << "<br>" << endl;
				cout << "제목 : " << a["title"] << "<br>" << endl;
				cout << "내용 : " << a["body"] << "<br>" << endl;
				cout << "<hr>" << endl;
			}
		}
		else if (action == "update") {

			string id = get_param("id");
			string title = get_param("title");
			string body = get_param("body");


			if (!id.empty()) {
				map<string, string> article;
				article["id"] = id;
				article["title"] = title;
				article["body"] = body;

				string file_name = "article_" + id + ".json";
				delete_json_file(file_name);
				make_article_to_jsonfile(article);
			}

			articles = get_all_articles();

			for (auto a : articles) {
				cout << "번호 : " << a["id"] << "<br>" << endl;
				cout << "제목 : " << a["title"] << "<br>" << endl;
				cout << "내용 : " << a["body"] << "<br>" << endl;
				cout << "<hr>" << endl;
			}
		}
		else if (action == "delete") {
			string id = get_param("id");

			if (!id.empty()) {
				string file_name = "article_" + id + ".json";
				delete_json_file(file_name);
			}
		}
		else if (action == "add") {
			string id = get_param("id");
			string title = get_param("title");
			string body = get_param("body");

			map<string, string> article;
			article["id"] = id;
			article["title"] = title;
			article["body"] = body;

			make_article_to_jsonfile(article);

		}
	}

	return 0;
}
