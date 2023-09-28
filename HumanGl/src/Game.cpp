  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/06 13:44:16 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "All.hpp"

Game::Game(void) : game_speed(1.0f), gravity(9.80665f) { }
Game::~Game(void) { }

void	Game::init(void)
{
	Object	tmp;
	Object	tmp2;

	/* initial camera position, unlocked */
	SDL_SetRelativeMouseMode(SDL_TRUE);
	this->pos[2] = -4.0f;
	this->pos[1] = 1.0f;
	this->pos_locked = 8.0f;
	this->obj.reserve(1000);


	/* obj[0] Tronc*/
	tmp.model = Matrix();
	tmp.rotate = Matrix().rotate(0,0,0);
	tmp.translate = Matrix().translate(0,0,0);
	tmp.root_part = 0;
	tmp.dimensions = {1.5f,5,1.5f};
	tmp.color = 0x0eaeae;
	this->obj.push_back(tmp);
	this->origin.push_back(tmp);

	/* obj[1] tete*/
	tmp.model = Matrix();
	tmp.rotate = Matrix().rotate(0,0,0);
	tmp.translate = Matrix().translate(0,3,0);
	tmp.root_part = &this->obj[0];
	tmp.dimensions = {2,2,2};
	tmp.color = 0xFFA07A;
	this->obj.push_back(tmp);
	this->origin.push_back(tmp);

	/* obj[2] articulation bras droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0.2f);
	tmp2.translate = Matrix().translate(1,1.5f,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {0.6f,0.6f,0.6f};
	tmp2.color = 0x0eaeae;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	/* obj[3] bras droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[2];
	tmp2.dimensions = {0.6f,2.5f,0.6f};
	tmp2.color = 0x0eaeae;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	/* obj[4] articulation bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,-0.2f);
	tmp2.translate = Matrix().translate(-1,1.5f,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {0.6f,0.6f,0.6f};
	tmp2.color = 0x0eaeae;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	/* obj[5] bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[4];
	tmp2.dimensions = {0.6f,2.5f,0.6f};
	tmp2.color = 0x0eaeae;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);


/* obj[6] articulation jambe droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0.3f,-2.5f,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	/* obj[7] articulation jambe gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(-0.3f,-2.5f,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);


	/* obj[8] jambe droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[6];
	tmp2.dimensions = {0.6f,2.5f,0.9f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);


	/* obj[9] jambe gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[7];
	tmp2.dimensions = {0.6f,2.5f,0.9f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);


	/* obj[10] articulation coude droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[3];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0xff8080;
	this->obj.push_back(tmp2);	
	this->origin.push_back(tmp2);
	
	/* obj[11] articulation coude gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[5];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0xff8080;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	/* obj[12] avant bras droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[10];
	tmp2.dimensions = {0.6f,2.5f,0.6f};
	tmp2.color = 0x0eaeae;
	this->obj.push_back(tmp2);	
	this->origin.push_back(tmp2);
	
	/* obj[13] avant bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[11];
	tmp2.dimensions = {0.6f,2.5f,0.6f};
	tmp2.color = 0x0eaeae;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	/* obj[14] articulation rotule droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[8];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);	
	this->origin.push_back(tmp2);
	
	/* obj[15] articulation rotule gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[9];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);


	/* obj[16] molet droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[14];
	tmp2.dimensions = {0.6f,2.5f,0.9f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);	
	this->origin.push_back(tmp2);
	
	/* obj[17] molet gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[15];
	tmp2.dimensions = {0.6f,2.5f,0.9f};
	tmp2.color = 0x6b6b6b;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);
	


	
	/* obj[18] main droite*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1.5f,0);
	tmp2.root_part = &this->obj[12];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0xFFA07A;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

		
	/* obj[19] main gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1.5f,0);
	tmp2.root_part = &this->obj[13];
	tmp2.dimensions = {0.5f,0.5f,0.5f};
	tmp2.color = 0xFFA07A;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

	
	/* obj[20] pied droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1.4f,-0.3f);
	tmp2.root_part = &this->obj[16];
	tmp2.dimensions = {0.5f,0.3f,1.3f};
	tmp2.color = 0xFFA07A;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);

		
	/* obj[21] pied gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1.4f,-0.3f);
	tmp2.root_part = &this->obj[17];
	tmp2.dimensions = {0.5f,0.3f,1.3f};
	tmp2.color = 0xFFA07A;
	this->obj.push_back(tmp2);
	this->origin.push_back(tmp2);
}

/* ########################################################################## */

void		Game::_update_camera(float delta, const Keys &key)
{
	float	delta_x;
	float	delta_z;

	/* lock - unlock camera and cursor */
	if (this->camera_lock != (enum e_camera)key.mouse_middle)
	{
		this->camera_lock = key.mouse_middle ? Locked : Unlocked;
		if (this->camera_lock == Unlocked)
			SDL_SetRelativeMouseMode(SDL_TRUE);
		else if (this->camera_lock == Locked)
			SDL_SetRelativeMouseMode(SDL_FALSE);
	}

	/* set then cap look angles */
	this->look_yaw += (key.mouse_x * MOUSE_SENSITIVITY_X) / 100000.0f;
	this->look_pitch += (key.mouse_y * MOUSE_SENSITIVITY_Y) / 100000.0f;
	if (this->look_pitch < -LOOK_CAP_PITCH)
		this->look_pitch = -LOOK_CAP_PITCH;
	if (this->look_pitch > LOOK_CAP_PITCH)
		this->look_pitch = LOOK_CAP_PITCH;
	if (this->camera_lock == Locked && this->look_pitch < LOOK_CAP_PITCH_LOCK)
		this->look_pitch = LOOK_CAP_PITCH_LOCK;

	/* set and cap positions */
	this->pos[1] += (unsigned)key.space * delta * CAMERA_SPEED -
	(unsigned)key.lshift * delta * CAMERA_SPEED;
	if (this->pos[1] < POS_CAP_Y)
		this->pos[1] = POS_CAP_Y;
	
	delta_x = (unsigned)key.d * delta * CAMERA_SPEED -
	(unsigned)key.a * delta * CAMERA_SPEED;
	delta_z = (unsigned)key.w * delta * CAMERA_SPEED -
	(unsigned)key.s * delta * CAMERA_SPEED;
	this->pos[0] += delta_z * sinf(this->look_yaw) +
	delta_x * sinf(this->look_yaw + (float)M_PI_2);
	this->pos[2] += delta_z * cosf(this->look_yaw) +
	delta_x * cosf(this->look_yaw + (float)M_PI_2);

	this->pos_locked += key.mouse_scroll / 1000.0f * SCROLL_SENSITIVITY;
	if (this->pos_locked < 0)
		this->pos_locked = 0;

	glUniform3fv(all.gl.uniform.camera_pos, 1, this->pos.data());
}

void 	Game::_reset_position()
{
	for (unsigned long i = 0; i < obj.size() ; i++)
	{
		obj[i].rotate = origin[i].rotate;
		obj[i].model = origin[i].model;
	 }

}
void		Game::_update_objects(float delta, const Keys &key)
{
	(void)key;
	static float	elapsed_time = 0;
	static float 	anim = 0;
	delta *= this->game_speed;
	static	int	playanim = 0;
	
	static float timer = 0;
	if (key.up && !key.left)
	{
		playanim = 1;
	}
	if (key.up && key.left && timer == 0)
	{
		playanim = 2;
	}
	if (key.left && !key.up && playanim == 0)
	{
		elapsed_time += delta;
		if (sin(elapsed_time*5) * delta*5< 0)
			anim = 1;
		obj[0].model.translate(0,sin(elapsed_time *10) * delta,0);
		obj[2].rotate.rotate(cos(elapsed_time * 5) * delta* 5, 0, 0);
		obj[4].rotate.rotate(cos(elapsed_time * 5) * -delta* 5 , 0, 0);
		obj[6].rotate.rotate(cos(elapsed_time * 5) * delta* 5 , 0, 0);
		obj[7].rotate.rotate(cos(elapsed_time * 5) * -delta* 5 , 0, 0);
		obj[10].rotate.rotate((sin(elapsed_time * 5) * delta* 5)/2 , 0, 0);
		obj[15].rotate.rotate(-sin(elapsed_time * 5)/2 * delta * 5, 0, 0);
		if (anim == 1)
		{
			obj[11].rotate.rotate((-sin(elapsed_time * 5) * delta* 5)/2 , 0, 0);
			obj[14].rotate.rotate(sin(elapsed_time * 5)/2 * delta* 5 , 0, 0);

		}
	}
	else if (playanim != 0 && timer <= 0.75)
	{
		if (playanim == 2 ){
			_reset_position();
			elapsed_time = 0;
			playanim =1 ;

		}
		elapsed_time += delta;
		timer += delta;
		obj[0].model.translate(0,sin(timer *8)/2 * delta *32,0);
		obj[2].rotate.rotate(0, 0 , sin(timer * 8) * delta * 8);
		obj[4].rotate.rotate(0, 0 , -sin(timer * 8) * delta * 8);
		obj[6].rotate.rotate(0, 0 , sin(timer * 8) * delta * 8);
		obj[7].rotate.rotate(0, 0 , -sin(timer * 8) * delta * 8);
	}
	else {
		playanim = 0;
		_reset_position();
		elapsed_time = 0;
		timer = 0;
		anim = 0;
	}
}

void		Game::update(float delta, const Keys &key)
{
	this->_update_camera(delta, key);
	this->_update_objects(delta, key);
}
