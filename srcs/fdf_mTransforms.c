/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mTransforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:34:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/06 12:35:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

// Define the camera position
double camX = 0;
double camY = 0;
double camZ = -10;

// Define the field of view
double fov = 60;

// Define the screen dimensions
int screenWidth = 800;
int screenHeight = 600;

// Define the projection matrix
double projectionMatrix[4][4] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 1/camZ, 0}
};

// Define the transformation matrix
double transformationMatrix[4][4] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
};

// Define a function to project a 3D point to a 2D point
void project(double x, double y, double z, double *x2d, double *y2d) {
	// Apply the transformation matrix
	double xTransformed = x * transformationMatrix[0][0] + y * transformationMatrix[1][0] + z * transformationMatrix[2][0] + transformationMatrix[3][0];
	double yTransformed = x * transformationMatrix[0][1] + y * transformationMatrix[1][1] + z * transformationMatrix[2][1] + transformationMatrix[3][1];
	double zTransformed = x * transformationMatrix[0][2] + y * transformationMatrix[1][2] + z * transformationMatrix[2][2] + transformationMatrix[3][2];
	double wTransformed = x * transformationMatrix[0][3] + y * transformationMatrix[1][3] + z * transformationMatrix[2][3] + transformationMatrix[3][3];

	// Apply the projection matrix
	double xProjected = xTransformed * projectionMatrix[0][0] + yTransformed * projectionMatrix[1][0] + zTransformed * projectionMatrix[2][0] + wTransformed * projectionMatrix[3][0];
	double yProjected = xTransformed * projectionMatrix[0][1] + yTransformed * projectionMatrix[1][1] + zTransformed * projectionMatrix[2][1] + wTransformed * projectionMatrix[3][1];
	double zProjected = xTransformed * projectionMatrix[0][2] + yTransformed * projectionMatrix[1][2] + zTransformed * projectionMatrix[2][2] + wTransformed * projectionMatrix[3][2];
	double wProjected = xTransformed * projectionMatrix[0][3] + yTransformed * projectionMatrix[1][3] + zTransformed * projectionMatrix[2][3] + wTransformed * projectionMatrix[3][3];

	// Normalize the projected coordinates
	*x2d = (xProjected / wProjected + 1) * screenWidth / 2;
	*y2d = (yProjected / wProjected + 1) * screenHeight / 2;
}
