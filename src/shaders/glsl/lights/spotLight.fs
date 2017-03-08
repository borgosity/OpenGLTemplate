// shadertype = glsl
#version 330 core
struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
	sampler2D texture_emissive1;
    float shininess;
}; 

struct Light {
    vec3 position;
    vec3 direction;
	float cuttOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
    float linear;
    float quadratic;
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
out vec4 color;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;
uniform int hasEmissive;

void main()
{
	vec3 lightDir = normalize(light.position - FragPos);
    
    // Check if lighting is inside the spotlight cone
    float theta = dot(lightDir, normalize(-light.direction)); 

    if(theta > light.cutOff) //angles as cosines instead of degrees so a '>' is used.
    { 
		// Ambient
		vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, TexCoords));
  	
		// Diffuse 
		vec3 norm = normalize(Normal);  
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = light.diffuse * diff * vec3(texture(material.texture_diffuse1, TexCoords));  
    
		// Specular
		vec3 viewDir = normalize(viewPos - FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);  
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
		vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, TexCoords));

		if (hasEmissive == 0){
			color = vec4(ambient + diffuse + specular, 1.0f); 
		}
		else {
			// Emission
			vec3 emission = vec3(texture(material.texture_emissive1, TexCoords)); 
			// final colour
			color = vec4(ambient + diffuse + specular + emission, 1.0f);  
		}
	}
	else {
		// else, use ambient light so scene isn't completely dark outside the spotlight.
        color = vec4(light.ambient * vec3(texture(material.diffuse, TexCoords)), 1.0f);
	}
}