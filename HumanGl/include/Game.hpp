/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/05 15:06:36 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "General.hpp"	/* vec3 */
# include "Event.hpp"	/* Keys */
# include "Object.hpp"	/* Object */
# include <vector>

enum e_camera
{
	Unlocked,
	Locked
};

struct Game
{
	public :
		Game(void);
		virtual ~Game(void);

		void	init(void);
		void	update(float delta, const Keys &key);

		enum e_camera	camera_lock;
		vec3			pos;
		float			pos_locked;

		float			look_yaw;	/* applied before pitch */
		float			look_pitch;

		std::vector<Object>	obj;	/* All objects */
		std::vector<Object>	origin;	/* copy objects */

		float			game_speed;
		float			gravity;

	private :
		void	_update_camera(float delta, const Keys &key);
		void	_update_objects(float delta, const Keys &key);
		void 	_reset_position();

};

#endif
