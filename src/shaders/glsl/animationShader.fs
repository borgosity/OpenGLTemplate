// shadertype = glsl
#version 410 core

in VS_OUT {
	vec3 Position;
	vec3 Normal;
	vec2 TexCoord;
} fs_in;

out vec4 fragColor;

// light
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool blinn;

// Texture samplers
uniform sampler2D texture_diffuse;
uniform sampler2D texture_specular;
uniform sampler2D texture_emissive;

void main()
{
    // set a default color to catch bugs
	vec3 color = vec3(0.1f, 0.2f, 0.3f);
	vec3 red = vec3(0.9f, 0.5f, 0.0f);

	// assign textures
	color = texture(texture_diffuse, fs_in.TexCoord).rgb;

    // Ambient
    vec3 ambient = 0.05 * color;
    // Diffuse
    vec3 lightDir = normalize(lightPos - fs_in.Position);
    vec3 normal = normalize(fs_in.Normal);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * red;
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
    vec3 specular = vec3(0.8, 0.0, 0.0) * spec; // assuming bright white light color

	fragColor = vec4(ambient + diffuse + specular, 1.0f);
}
