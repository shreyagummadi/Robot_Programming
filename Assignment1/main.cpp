#include <iostream>
#include <array>
#include <vector>
#include <string>


std::vector<std::string> load_color_vecs(std::array<std::string, 2> peg_array)
 {
     std::vector<std::string> color_vec;
     for(int i=0; i<2; i++)
         {
             color_vec.push_back(peg_array.at(i));
         }
     return color_vec;
 }

void print_2d_vector(std::vector<std::vector<std::string>> color_vec_2d)
{
    for (unsigned int i=0; i<color_vec_2d.size(); i++)
    {
        for (unsigned int j=0; j<color_vec_2d.at(i).size(); j++)
        {
            std::cout << color_vec_2d.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}
        

int main()
{
	std::array<std::array<std::string, 2>, 3> peg_array {{{"blue","white"},{"green","white"},{"green","white"}}};
    std::vector<std::string> color_vec1, color_vec2, color_vec3;
    color_vec1 = load_color_vecs(peg_array.at(0));
    color_vec2 = load_color_vecs(peg_array.at(1));
    color_vec3 = load_color_vecs(peg_array.at(2));
    
    std::cout << "Enter color of missing pegs using the picture of the peg tray starting from top row to bottom row: "<< std::endl;
    std::string missing_color1, missing_color2, missing_color3;
    std::cin >> missing_color1 >> missing_color2 >> missing_color3;
    
    color_vec1.push_back(missing_color1);
    color_vec2.insert(color_vec2.begin(), missing_color2);
    color_vec3.insert(color_vec3.begin()+1, missing_color3);
    
    std::cout << "Vector 1: " << color_vec1.at(0) << "  " << color_vec1.at(1) << "  " << color_vec1.at(2) << std::endl;
    std::cout << "Vector 2: " << color_vec2.at(0) << "  " << color_vec2.at(1) << "  " << color_vec2.at(2) << std::endl;
    std::cout << "Vector 3: " << color_vec3.at(0) << "  " << color_vec3.at(1) << "  " << color_vec3.at(2) << std::endl;
    
    std::vector<std::vector<std::string>> color_vec_2d {{{color_vec1},{color_vec2},{color_vec3}}};
    print_2d_vector(color_vec_2d);
    return 0;
}