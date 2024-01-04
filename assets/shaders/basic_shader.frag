#version 330 core
	
out vec4 FragColor;
in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform sampler2D tex2;

uniform vec4 lightColor;

void main() {
	FragColor = texture(tex0, texCoord), texture(tex1, texCoord), texture(tex2, texCoord) * lightColor;
}
	