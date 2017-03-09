// shadertype = glsl
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out VS_OUT{
	vec3 Position;
	vec3 Normal;
	vec2 TexCoord;
} vs_out;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

uniform sampler2D texture_perlin;

void main()
{

	vec3 pos = position;
	pos.y += texture(texture_perlin, texCoord).r * 5.0f;
	//pos.y += texture(texture_perlin, texCoord).r * sin(time + pos.x);

    vs_out.Position = position;
    vs_out.Normal = normal;
    vs_out.TexCoord = texCoord;
    
	gl_Position = projection * view * model * vec4(pos, 1.0f);
}
