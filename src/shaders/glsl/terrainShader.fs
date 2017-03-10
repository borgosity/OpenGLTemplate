// shadertype = glsl
#version 330 core

in VS_OUT {
	vec3 Position;
	vec3 Normal;
	vec2 TexCoord;
	float yHeight;
} fs_in;


out vec4 fragColor;

// light
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool blinn;

// terrain uniforms
uniform vec3 mapTex;


// Texture samplers
uniform sampler2D texture_grass;
uniform sampler2D texture_sand;
uniform sampler2D texture_dirt;
uniform sampler2D texture_water;
uniform sampler2D texture_snow;
uniform sampler2D texture_perlin;

void main()
{
    // set a default color to catch bugs
	vec3 color = vec3(0.1f, 0.2f, 0.3f);
	// set textures to tile by myuliplying the texture coordinates greater than 1
	vec2 tileTex = fs_in.TexCoord * 64.0f;

	if (fs_in.yHeight < mapTex.x)
		color = texture(texture_water, tileTex).rgb;
	else if (fs_in.yHeight < (mapTex.x + 0.05f))
		color = texture(texture_sand, tileTex).rgb;
	else if (fs_in.yHeight < mapTex.y )
		color = texture(texture_grass, tileTex).rgb;
	else if (fs_in.yHeight < (mapTex.y + 0.05f))
		color = texture(texture_dirt, tileTex).rgb;
	else
		color = texture(texture_snow, tileTex).rgb;

    // Ambient
    vec3 ambient = 0.05 * color;
    // Diffuse
    vec3 lightDir = normalize(lightPos - fs_in.Position);
    vec3 normal = normalize(fs_in.Normal);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;
    // Specular
    vec3 viewDir = normalize(viewPos - fs_in.Position);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    if(blinn)
    {
        vec3 halfwayDir = normalize(lightDir + viewDir);  
        spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    }
    else
    {
        vec3 reflectDir = reflect(-lightDir, normal);
        spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
    }
    vec3 specular = vec3(0.3) * spec; // assuming bright white light color
    fragColor = vec4(ambient + diffuse + specular, 1.0f);
}
