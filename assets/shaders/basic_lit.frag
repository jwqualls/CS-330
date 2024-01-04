#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoord;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main() {
    //ambient
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.f, 1.f, 1.f);

    vec3 ambient = ambientStrength * lightColor;

    vec3 objectColor = vertexColor.xyz;

    vec3 finalColor = objectColor * ambient;
    FragColor = vec4(finalColor, 1.0);
}