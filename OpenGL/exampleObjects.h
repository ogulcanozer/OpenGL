//Example object vertices with position and texture coordinates
unsigned int  posQuad[] = {
	-0.5f , -0.5f , 0.0f, 0.0f,
	0.5f , -0.5f , 1.0f, 0.0f,
	0.5f ,  0.5f , 1.0f, 1.0f,
	-0.5f ,  0.5f , 0.0f, 1.0f
};
int quadSize = 16;
unsigned int  idxQuad[] = {
	0, 1, 2,
	2, 3, 0
};
int quadIdxSize = 6;
unsigned int  posCube[] = {
	.5f, .5f, .5f, 1, 0,  -.5f, .5f, .5f,0, 0,  -.5f,-.5f, .5f,0, 1,  .5f,-.5f, .5f,1, 1, 
	.5f, .5f, .5f, 0, 0,   .5f,-.5f, .5f,0, 1,   .5f,-.5f,-.5f,1, 1,  .5f, .5f,-.5f,1, 0, 
	.5f, .5f, .5f, 1, 1,   .5f, .5f,-.5f,1, 0,  -.5f, .5f,-.5f,0, 0, -.5f, .5f, .5f,0, 1, 
	-.5f, .5f, .5f, 1, 0,  -.5f, .5f,-.5f,0, 0,  -.5f,-.5f,-.5f,0, 1, -.5f,-.5f, .5f,1, 1,
	-.5f,-.5f,-.5f, 0, 1,   .5f,-.5f,-.5f,1, 1,   .5f,-.5f, .5f,1, 0, -.5f,-.5f, .5f,0, 0,
	.5f,-.5f,-.5f, 0, 1,  -.5f,-.5f,-.5f,1, 1,  -.5f, .5f,-.5f,1, 0,  .5f, .5f,-.5f,0, 0  
};
int cubeSize = 120;
unsigned int idxCube[] = {
	0, 1, 2,   2, 3, 0,
	4, 5, 6,   6, 7, 4,
	8, 9,10,  10,11, 8,
	12,13,14,  14,15,12,
	16,17,18,  18,19,16,
	20,21,22,  22,23,20
};
int cubeIdxSize = 36;