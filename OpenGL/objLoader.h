#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)
class objLoader {
private:

    struct objInfo {
        int numPos;
        int numVertex;
        int numTexCoord;
        int numt_normal;
        int numFace;
    };


public:

    objInfo m_Info;
    std::vector<unsigned int> indices;
    std::vector<float> posTex;
    std::vector<float> position;
    std::vector<float> texture;
    std::vector<float> normal;
    //std::vector<std::vector<float>> position;
    //std::vector<std::vector<float>> texture;
    //std::vector<std::vector<float>> normal;
    objLoader(const std::string path) {
        m_Info = getObjFileInfo(path);
        //position = std::vector<std::vector<float>>(m_Info.numFace, std::vector<float>(3));
        //texture = std::vector<std::vector<float>>(m_Info.numFace, std::vector<float>(2));
        //normal = std::vector<std::vector<float>>(m_Info.numFace, std::vector<float>(3));
        getOBJdata(path);
    }
    ~objLoader() {
    }

    objInfo getObjFileInfo(const std::string path) {
        std::string fp = path;
        objInfo info = { 0 };
        // Open OBJ file
        std::ifstream inp;
        inp.open(fp);
        if (inp.is_open()) {

            std::string line;

            while (std::getline(inp, line))
            {

                std::string type = line.substr(0, 2);

                if (type.compare("v ") == 0)
                    info.numPos++;
                else if (type.compare("vt") == 0)
                    info.numTexCoord++;
                else if (type.compare("vn") == 0)
                    info.numt_normal++;
                else if (type.compare("f ") == 0)
                    info.numFace++;
            }
        }

        info.numVertex = info.numFace * 3;
        inp.close();


        return info;
    }
    void getOBJdata(std::string path) {
        std::vector<float> t_position;
        std::vector<float> t_texture;
        std::vector<float> t_normal;
        std::vector<unsigned int> t_face;

        std::string fpath = path;
        std::ifstream inp;
        inp.open(fpath);
        if (inp.is_open()) {

            std::string line;

            while (std::getline(inp, line))
            {

                std::string type = line.substr(0, 2);

                // t_positions
                if (type.compare("v ") == 0)
                {
                    // 1
                    // Copy line for parsing
                    char* l = new char[line.size() + 1];
                    memcpy(l, line.c_str(), line.size() + 1);

                    // 2
                    // Extract tokens
                    strtok(l, " ");
                    for (int i = 0; i < 3; i++)
                        t_position.push_back(atof(strtok(NULL, " ")));

                    // 3
                    // Wrap up
                    delete[] l;

                }

                // Texels
                else if (type.compare("vt") == 0)
                {
                    char* l = new char[line.size() + 1];
                    memcpy(l, line.c_str(), line.size() + 1);

                    strtok(l, " ");
                    for (int i = 0; i < 2; i++)
                        t_texture.push_back(atof(strtok(NULL, " ")));

                    delete[] l;

                }

                // t_normals
                else if (type.compare("vn") == 0)
                {
                    char* l = new char[line.size() + 1];
                    memcpy(l, line.c_str(), line.size() + 1);

                    strtok(l, " ");
                    for (int i = 0; i < 3; i++)
                        t_normal.push_back(atof(strtok(NULL, " ")));

                    delete[] l;

                }

                // Faces
                else if (type.compare("f ") == 0)
                {
                    char* l = new char[line.size() + 1];
                    memcpy(l, line.c_str(), line.size() + 1);

                    strtok(l, " ");
                    for (int i = 0; i < 9; i++)
                        t_face.push_back(atof(strtok(NULL, "/ ")));

                    delete[] l;
                }
            }
        }

        inp.close();
        for (int i = 0; i < t_face.size(); i += 3) {

            int p = t_face[i] - 1;
            int t = t_face[i + 1] - 1;
            int n = t_face[i + 2] - 1;
            indices.push_back(i / 3);
            p *= 3;
            t *= 2;
            n *= 3;
            //position[i / 3][0] = t_position[p];
            //position[i / 3][1] = t_position[p+1];
            //position[i / 3][2] = t_position[p+2];

            //texture[i / 3][0] = t_texture[t];
            //texture[i / 3][1] = t_texture[t + 1];
            //texture[i / 3][2] = t_texture[t + 2];

            //normal[i / 3][0] = t_normal[n];
            //normal[i / 3][1] = t_normal[n + 1];
            //normal[i / 3][2] = t_normal[n + 2];

            posTex.insert(posTex.end(), { t_position[p],t_position[p + 1] ,t_position[p + 2], t_texture[t], t_texture[t + 1] });
            position.insert(position.end(), { t_position[p],t_position[p + 1] ,t_position[p + 2] });
            texture.insert(texture.end(), { t_texture[t], t_texture[t + 1] });
            normal.insert(normal.end(), { t_normal[n],t_normal[n + 1] ,t_normal[n + 2] });
        }
    }


};
