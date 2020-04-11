#include <iostream>
#include <fstream>

void create_header(std::string name)
{
	std::string cap(name);
	int len = name.size();
	std::ofstream header(name + ".hpp");
	header << "#ifndef ";
	for(int i = 0; i < len; i++)
		cap[i] = toupper(cap[i]);
	header << cap << "_HPP" << std::endl;
	header <<"#define " << cap << "_HPP" << std::endl;
	header << "#include <iostream>" << std::endl << std::endl;
	header << "class " << name << std::endl;
	header << "{" << std::endl;
	header << "\tpublic:" << std::endl;
	header << "\t\t" << name << "();" << std::endl;
	header << "\t\t" << name << "(const " << name << "&);" << std::endl;
	header << "\t\t" << name << "& " << "operator=" << "(const " << name << "&);" << std::endl;
	header << "\t\t~" << name << "();" << std::endl;
	header << "};" << std::endl;
	header << "#endif" << std::endl;
	header.close();
}

void create_cpp(std::string name)
{
	std::string classic(name + "::");
	int len = name.size();
	std::ofstream cpp(name + ".cpp");
	cpp << "#include \"" << name << ".hpp\"" << std::endl << std::endl;
 	cpp << classic << name << "()\n{}\n" << std::endl;
	cpp << classic << name << "(const " << name <<"& other)\n{}\n" << std::endl;
	cpp << name << "& " << classic << "operator=" << "(const " << name << "& other)\n{}\n" << std::endl;
	cpp << classic << "~" << name << "()\n{}\n" << std::endl;
	cpp.close();
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string name(argv[1]);
		create_header(name);
		create_cpp(name);
	}
	return 0;
}
