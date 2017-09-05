#include <simplecpp>
/* at the beginning of main program , there are 2 parameters namely :
 * velocity_k and g. 
 * We can vary these parameters to change the projectile speed as required.
 * To increase the speed , increase both the parameters (preferably in the same ratio).
 * g determines gravity.
 */
bool prime(int x) {
	bool p = true ;
	for(int i = 2 ; i < sqrt(x * 1.0) ; i++) {
		if(x % i == 0)
			p = false ;
	}
	return p ;
}
int randnum() {
	time_t a ;
	int x = time(&a) ;
	x = x % 9999 ;
	int c ;
	for(c = x ; c > 2 ; c--)
		if(prime(c) == true)
			break ;
	return c ;
}
int canvasWidth = 1000 , canvasHeight = 600 ;
int wpnactive1 = 00 , wpnactive2 = 00 ;
int wpcd1(int x , int y) {
	int a;
	bool selecta = false ;
	if(x < 505 + textWidth("QUIT") / 2 && x > 495 - textWidth("QUIT") && y > 45 - textHeight() / 2 && y < 55 + textHeight() / 2) {
		return (-2) ;
	}
	for(int i = (200 - (textHeight() / 2) - 2) ; i <= (380 - (textHeight() / 2) - 2) ; i = i + 20) {
		if(x <= (202 + textWidth("HOMING MISSILE") / 2) && x >= (198 - textWidth("HOMING MISSILE") / 2)) {
			if(i <= y && y < (i + 20)) {
				a = ((i + (textHeight() / 2) + 2) / 20 - 10);
				selecta = true ;
				break;
			}
		}
	}
	if(selecta == true)
		return a ;
	else
		return (-1) ;
}
int wpcd2(int x , int y) {
	int a;
	bool selecta = false ;
	if(x < 505 + textWidth("QUIT") / 2 && x > 495 - textWidth("QUIT") && y > 45 - textHeight() / 2 && y < 55 + textHeight() / 2) {
		return (-2) ;
	}
	for(int i = (200 - (textHeight() / 2) - 2) ; i <= (380 - (textHeight() / 2) - 2) ; i = i + 20) {
		if(x <= (802 + textWidth("HOMING MISSILE") / 2) && x >= (798 - textWidth("HOMING MISSILE") / 2)) {
			if(i <= y && y < (i + 20)) {
				a = ((i + (textHeight() / 2) + 2) / 20 - 10) ;
				selecta = true ;
				break;
			}
		}
	}
	if(selecta == true)
		return a ;
	else
		return (-1) ;
}
string wpns(int wcode) {
	string wname ;
	if(wcode == 10)
		return "WORM" ;
	else if(wcode == 11)
		return "ZAPPER" ;
	else if(wcode == 12)
		return "PILE DRIVER" ;
	else if(wcode == 13)
		return "BIG SHOT" ;
	else if(wcode == 14)
		return "SPIDER" ;
	else if(wcode == 15)
		return "GAMMA BLASTER" ;
	else if(wcode == 16)
		return "HOMING MISSILE" ;
	else if(wcode == 17)
		return "HEATSEEKER" ;
	else if(wcode == 18)
		return "FIREBALL" ;
	else if(wcode == 19)
		return "CRAZY IVAN" ;
	else if(wcode == 20)
		return "GROUND HOG" ;
	else if(wcode == 21)
		return "SNIPER RIFLE" ;
	else if(wcode == 22)
		return "FIRE CRACKER" ;
	else if(wcode == 23)
		return "CHAIN REACTION" ;
	else if(wcode == 24)
		return "NAPALM" ;
	else if(wcode == 25)
		return "JACK HAMMER" ;
	else if(wcode == 26)
		return "HAIL STORM" ;
	else if(wcode == 27)
		return "FLASH BLAST" ;
	else if(wcode == 28)
		return "SONIC BLAST" ;
	else if(wcode == 29)
		return "SUPER NOVA" ;
	else return "";
}
class tanks{
	public :
	int score ;
	float x , y ;
	int weapon[10] ;
	bool isused[10] ;
	tanks() {
		score = 0 ;
		x = 0 ;
		y = 0 ;
		for(int k = 0 ; k < 10 ; k++) {
			isused[k] = false ;
		}
	}
} ;
void assignrand(tanks* tanks1 , tanks* tanks2) {
	int k , l ;
	k = randnum() ;
	for(int j = 1 ; j <= 10 ; j++) {
		if(j%2 != 0) {
			l = (k * j) % 11 ;
			(*tanks1).weapon[j - 1] = l + 9 ;
		}
		else {
			l = (k * j) % 9 ;
			(*tanks1).weapon[j - 1] = l + 20 ;
		}
	}
	l = 0 , k = 0 ;
	bool present = false ;
	for(int j = 10 ; j <= 29 ; j++) {
		for(k = 0 ; k < 10 ; k++) {
			if(j == (*tanks1).weapon[k]) {
				present = true ;
				break ;
			}
		}
		if(present == false) {
			(*tanks2).weapon[l] = j ;
			l++ ;
		}
		present = false ;
	}
}
int main() {
	while(true) {
	initCanvas("BlasTanks" , canvasWidth , canvasHeight) ;
	float velocity_k = 0.01 ;
	int tankW = 60 , tankH = 40 ;
	float g = 0.005 ;
	tanks tanks1 ;
	tanks tanks2 ;
	
	//Last Click
	Circle LastClick1, LastClick2;
	LastClick1.setFill(true);
	LastClick1.setColor(COLOR(30,0,0),true);
	LastClick2.setFill(true);
	LastClick2.setColor(COLOR(0,0,30),true);
	
	
	//instructions
	Text info_wpn1, info_wpn2, info_wpn3;
	Text info1[12];
	
	Text loading_1(500 , 400 , "LOADING...") ;
	loading_1.imprint() ;
	Text credits_1(500 , 300 , "CREDITS : AASHISH RATHI & AMAN GOEL") ;
	credits_1.imprint() ;
	Text title_1(500 , 200 , "BLASTANKS") ;
	title_1.scale(5) ;
	title_1.imprint() ;
	//sky
	Circle exp_1;
	Rectangle exp_r1 ;
	Line exp_l1 ;
	float sky_r = 250.0 , sky_g = 222.0 , sky_b = 156.0 ;
	Rectangle bg(500 , 300 , 1000 , 600) ;
	bg.setFill(true) ;
	bg.setColor(COLOR(sky_r , sky_g , sky_b) , true) ;
	bg.imprint() ;
	bg.hide() ;
	for(int sky_c = 270 ; sky_c >= 0 ; sky_c = sky_c - 1) {
		bg.reset(500 , sky_c , 1000 , 2*sky_c) ;
		bg.setFill(true) ;
		bg.setColor(COLOR(sky_r*(0.2 + sky_c/337.5) , sky_g*(0.2 + sky_c/337.5) , sky_b*(0.2 + sky_c/337.5)) , true) ;
		bg.imprint() ;
		bg.hide() ;
	}
	
	
	int game = 0;
	
	loading_1.hide() ;
	credits_1.hide() ;
	title_1.hide() ;
	while(true) {
		Text quit1(500 , 400 , "QUIT") ;
		quit1.setFill(true) ;
		quit1.setColor(COLOR(255 , 255 , 255) , true) ;
		Rectangle quit1_r(500 , 400 , 10 + textWidth("QUIT") , 10 + textHeight()) ;
		quit1_r.setColor(COLOR(255 , 255 , 255) , true) ;
		Text instructions(500 , 300 , "PLAY WITH INSTRUCTIONS") ;
		instructions.setFill(true) ;
		instructions.setColor(COLOR(255 , 255 , 255) , true) ;
		Rectangle instructions_r(500 , 300 , 10 + textWidth("PLAY WITH INSTRUCTIONS") , 10 + textHeight()) ;
		instructions_r.setColor(COLOR(255 , 255 , 255) , true) ;
		Text playgame(500 , 200 , "PLAY") ;
		playgame.setFill(true) ;
		playgame.setColor(COLOR(255 , 255 , 255) , true) ;
		Rectangle playgame_r(500 , 200 , 10 + textWidth("PLAY") , 10 + textHeight()) ;
		playgame_r.setColor(COLOR(255 , 255 , 255) , true) ;
		int jj = getClick() ;
		int jj_x = jj / 65536 ;
		int jj_y = jj % 65536 ;
		if(jj_x < 505 + textWidth("PLAY") / 2 && jj_x > 495 - textWidth("PLAY") / 2 && jj_y < 205 + textHeight() / 2 && jj_y > 195 - textHeight() / 2) {
			instructions.hide() ;
			instructions_r.hide() ;
			playgame.hide() ;
			playgame_r.hide() ;
			game = 0;
			break ;
		}
		else if(jj_x < 505 + textWidth("PLAY WITH INSTRUCTIONS") / 2 && jj_x > 495 - textWidth("PLAY WITH INSTRUCTIONS") / 2 && jj_y < 305 + textHeight() / 2 && jj_y > 295 - textHeight() / 2) {
			instructions.hide() ;
			instructions_r.hide() ;
			playgame.hide() ;
			playgame_r.hide() ;
			game = 1;
			break ;
		}
		else if(jj_x < 505 + textWidth("PLAY") / 2 && jj_x > 495 - textWidth("PLAY") / 2 && jj_y < 405 + textHeight() / 2 && jj_y > 395 - textHeight() / 2) {
			return 0 ;
		}
		else
			continue ;
	}
	//weapons
	Text weapon_heading(500 , 100 , "WEAPON LIST") ;
	weapon_heading.setColor(COLOR(255 , 255 , 255) , true) ;
	int weapon_c1 = 300 , weapon_c2 = 700 , weapon_c3 = 250 , weapon_c4 = 30 , weapon_c5 = 100 , cl1 = 0 , cl2 = 0 ;
	bool weapon_p1[10] , weapon_p2[10] ;
	for(int z = 0 ; z < 10 ; z++) {
		weapon_p1[z] = false ;
		weapon_p2[z] = false ;
	}
	Text weapon_list1[10] ;
	weapon_list1[0].reset(weapon_c1 , weapon_c3 + 0*weapon_c4 , "WORM") ;
	weapon_list1[1].reset(weapon_c1 , weapon_c3 + 1*weapon_c4 , "ZAPPER") ;
	weapon_list1[2].reset(weapon_c1 , weapon_c3 + 2*weapon_c4 , "PILE DRIVER") ;
	weapon_list1[3].reset(weapon_c1 , weapon_c3 + 3*weapon_c4 , "BIG SHOT") ;
	weapon_list1[4].reset(weapon_c1 , weapon_c3 + 4*weapon_c4 , "SPIDER") ;
	weapon_list1[5].reset(weapon_c1 , weapon_c3 + 5*weapon_c4 , "GAMMA BLASTER") ;
	weapon_list1[6].reset(weapon_c1 , weapon_c3 + 6*weapon_c4 , "HOMING MISSILE") ;
	weapon_list1[7].reset(weapon_c1 , weapon_c3 + 7*weapon_c4 , "HEATSEEKER") ;
	weapon_list1[8].reset(weapon_c1 , weapon_c3 + 8*weapon_c4 , "FIREBALL") ;
	weapon_list1[9].reset(weapon_c1 , weapon_c3 + 9*weapon_c4 , "CRAZY IVAN") ;
	Text weapon_list2[10] ;
	weapon_list2[0].reset(weapon_c2 , weapon_c3 + 0*weapon_c4 , "GROUND HOG") ;
	weapon_list2[1].reset(weapon_c2 , weapon_c3 + 1*weapon_c4 , "SNIPER RIFLE") ;
	weapon_list2[2].reset(weapon_c2 , weapon_c3 + 2*weapon_c4 , "FIRE CRACKER") ;
	weapon_list2[3].reset(weapon_c2 , weapon_c3 + 3*weapon_c4 , "CHAIN REACTION") ;
	weapon_list2[4].reset(weapon_c2 , weapon_c3 + 4*weapon_c4 , "NAPALM") ;
	weapon_list2[5].reset(weapon_c2 , weapon_c3 + 5*weapon_c4 , "JACK HAMMER") ;
	weapon_list2[6].reset(weapon_c2 , weapon_c3 + 6*weapon_c4 , "HAIL STORM") ;
	weapon_list2[7].reset(weapon_c2 , weapon_c3 + 7*weapon_c4 , "FLASH BLAST") ;
	weapon_list2[8].reset(weapon_c2 , weapon_c3 + 8*weapon_c4 , "SONIC BLAST") ;
	weapon_list2[9].reset(weapon_c2 , weapon_c3 + 9*weapon_c4 , "SUPER NOVA") ;
	
	if(game == 1){
		info_wpn1.reset(canvasWidth/2, 200, "Select weapons by clicking on them.");
		info_wpn2.reset(canvasWidth/2, 250, "Each player selects one after another.");
		info_wpn3.reset(canvasWidth/2, 300, "You can also randomize.");
	}
	Text randomize_list(500 , 550 , "RANDOM") ;
	Rectangle zz(500 , 550 , textWidth("RANDOM") + 10 , textHeight() + 10) ;
	
	int chance = 1 , success = 0 , mx = 0 , my = 0 , click_w = 0 ;
	while(true) {
		click_w = getClick() ;
		mx = click_w / 65536 ; my = click_w % 65536 ;
		if(success == 20)
			break ;
		if(mx < 505 + textWidth("RANDOM") / 2 && mx > 495 - textWidth("RANDOM") / 2 && my > 545 - textHeight() / 2 && my < 555 + textHeight() / 2) {
			assignrand(&tanks1 , &tanks2) ;
			randomize_list.hide() ;
			zz.hide() ;
			break ;
		}
		if(weapon_p1[0] == false && mx <= (weapon_c1 + textWidth("WORM")/2.0) && mx >= (weapon_c1 - textWidth("WORM")/2.0) && my >= (weapon_c3 + 0*weapon_c4 - textHeight()) && my <= (weapon_c3 + 0*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[0].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "WORM") ; tanks1.weapon[cl1] = 10 ; cl1++ ; weapon_p1[0] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[0].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "WORM") ; tanks2.weapon[cl2] = 10 ; cl2++ ; weapon_p1[0] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[1] == false && mx <= (weapon_c1 + textWidth("ZAPPER")/2.0) && mx >= (weapon_c1 - textWidth("ZAPPER")/2.0) && my >= (weapon_c3 + 1*weapon_c4 - textHeight()) && my <= (weapon_c3 + 1*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[1].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "ZAPPER") ; tanks1.weapon[cl1] = 11 ; cl1++ ; weapon_p1[1] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[1].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "ZAPPER") ; tanks2.weapon[cl2] = 11 ; cl2++ ; weapon_p1[1] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[2] == false && mx <= (weapon_c1 + textWidth("PILE DRIVER")/2.0) && mx >= (weapon_c1 - textWidth("PILE DRIVER")/2.0) && my >= (weapon_c3 + 2*weapon_c4 - textHeight()) && my <= (weapon_c3 + 2*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[2].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "PILE DRIVER") ; tanks1.weapon[cl1] = 12 ; cl1++ ; weapon_p1[2] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[2].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "PILE DRIVER") ; tanks2.weapon[cl2] = 12 ; cl2++ ; weapon_p1[2] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[3] == false && mx <= (weapon_c1 + textWidth("BIG SHOT")/2.0) && mx >= (weapon_c1 - textWidth("BIG SHOT")/2.0) && my >= (weapon_c3 + 3*weapon_c4 - textHeight()) && my <= (weapon_c3 + 3*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[3].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "BIG SHOT") ; tanks1.weapon[cl1] = 13 ; cl1++ ; weapon_p1[3] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[3].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "BIG SHOT") ; tanks2.weapon[cl2] = 13 ; cl2++ ; weapon_p1[3] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[4] == false && mx <= (weapon_c1 + textWidth("SPIDER")/2.0) && mx >= (weapon_c1 - textWidth("SPIDER")/2.0) && my >= (weapon_c3 + 4*weapon_c4 - textHeight()) && my <= (weapon_c3 + 4*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[4].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "SPIDER") ; tanks1.weapon[cl1] = 14 ; cl1++ ; weapon_p1[4] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[4].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "SPIDER") ; tanks2.weapon[cl2] = 14 ; cl2++ ; weapon_p1[4] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[5] == false && mx <= (weapon_c1 + textWidth("GAMMA BLASTER")/2.0) && mx >= (weapon_c1 - textWidth("GAMMA BLASTER")/2.0) && my >= (weapon_c3 + 5*weapon_c4 - textHeight()) && my <= (weapon_c3 + 5*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[5].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "GAMMA BLASTER") ; tanks1.weapon[cl1] = 15 ; cl1++ ; weapon_p1[5] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[5].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "GAMMA BLASTER") ; tanks2.weapon[cl2] = 15 ; cl2++ ; weapon_p1[5] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[6] == false && mx <= (weapon_c1 + textWidth("HOMING MISSILE")/2.0) && mx >= (weapon_c1 - textWidth("HOMING MISSILE")/2.0) && my >= (weapon_c3 + 6*weapon_c4 - textHeight()) && my <= (weapon_c3 + 6*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[6].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "HOMING MISSILE") ; tanks1.weapon[cl1] = 16 ; cl1++ ; weapon_p1[6] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[6].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "HOMING MISSILE") ; tanks2.weapon[cl2] = 16 ; cl2++ ; weapon_p1[6] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[7] == false && mx <= (weapon_c1 + textWidth("HEATSEEKER")/2.0) && mx >= (weapon_c1 - textWidth("HEATSEEKER")/2.0) && my >= (weapon_c3 + 7*weapon_c4 - textHeight()) && my <= (weapon_c3 + 7*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[7].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "HEATSEEKER") ; tanks1.weapon[cl1] = 17 ; cl1++ ; weapon_p1[7] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[7].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "HEATSEEKER") ; tanks2.weapon[cl2] = 17 ; cl2++ ; weapon_p1[7] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[8] == false && mx <= (weapon_c1 + textWidth("FIREBALL")/2.0) && mx >= (weapon_c1 - textWidth("FIREBALL")/2.0) && my >= (weapon_c3 + 8*weapon_c4 - textHeight()) && my <= (weapon_c3 + 8*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[8].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "FIREBALL") ; tanks1.weapon[cl1] = 18 ; cl1++ ; weapon_p1[8] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[8].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "FIREBALL") ; tanks2.weapon[cl2] = 18 ; cl2++ ; weapon_p1[8] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p1[9] == false && mx <= (weapon_c1 + textWidth("CRAZY IVAN")/2.0) && mx >= (weapon_c1 - textWidth("CRAZY IVAN")/2.0) && my >= (weapon_c3 + 9*weapon_c4 - textHeight()) && my <= (weapon_c3 + 9*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list1[9].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "CRAZY IVAN") ; tanks1.weapon[cl1] = 19 ; cl1++ ; weapon_p1[9] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list1[9].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "CRAZY IVAN") ; tanks2.weapon[cl2] = 19 ; cl2++ ; weapon_p1[9] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[0] == false && mx <= (weapon_c2 + textWidth("GROUND HOG")/2.0) && mx >= (weapon_c2 - textWidth("GROUND HOG")/2.0) && my >= (weapon_c3 + 0*weapon_c4 - textHeight()) && my <= (weapon_c3 + 0*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[0].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "GROUND HOG") ; tanks1.weapon[cl1] = 20 ; cl1++ ; weapon_p2[0] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list2[0].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "GROUND HOG") ; tanks2.weapon[cl2] = 20 ; cl2++ ; weapon_p2[0] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[1] == false && mx <= (weapon_c2 + textWidth("SNIPER RIFLE")/2.0) && mx >= (weapon_c2 - textWidth("SNIPER RIFLE")/2.0) && my >= (weapon_c3 + 1*weapon_c4 - textHeight()) && my <= (weapon_c3 + 1*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[1].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "SNIPER RIFLE") ; tanks1.weapon[cl1] = 21 ; cl1++ ; weapon_p2[1] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list2[1].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "SNIPER RIFLE") ; tanks2.weapon[cl2] = 21 ; cl2++ ; weapon_p2[1] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[2] == false && mx <= (weapon_c2 + textWidth("FIRE CRACKER")/2.0) && mx >= (weapon_c2 - textWidth("FIRE CRACKER")/2.0) && my >= (weapon_c3 + 2*weapon_c4 - textHeight()) && my <= (weapon_c3 + 2*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[2].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "FIRE CRACKER") ; tanks1.weapon[cl1] = 22 ; cl1++ ; weapon_p2[2] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list2[2].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "FIRE CRACKER") ; tanks2.weapon[cl2] = 22 ; cl2++ ; weapon_p2[2] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[3] == false && mx <= (weapon_c2 + textWidth("CHAIN REACTION")/2.0) && mx >= (weapon_c2 - textWidth("CHAIN REACTION")/2.0) && my >= (weapon_c3 + 3*weapon_c4 - textHeight()) && my <= (weapon_c3 + 3*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[3].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "CHAIN REACTION") ; tanks1.weapon[cl1] = 23 ; cl1++ ; weapon_p2[3] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list2[3].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "CHAIN REACTION") ; tanks2.weapon[cl2] = 23 ; cl2++ ; weapon_p2[3] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[4] == false && mx <= (weapon_c2 + textWidth("NAPALM")/2.0) && mx >= (weapon_c2 - textWidth("NAPALM")/2.0) && my >= (weapon_c3 + 4*weapon_c4 - textHeight()) && my <= (weapon_c3 + 4*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[4].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "NAPALM") ; tanks1.weapon[cl1] = 24 ; cl1++ ; weapon_p2[4] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list2[4].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "NAPALM") ; tanks2.weapon[cl2] = 24 ; cl2++ ; weapon_p2[4] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[5] == false && mx <= (weapon_c2 + textWidth("JACK HAMMER")/2.0) && mx >= (weapon_c2 - textWidth("JACK HAMMER")/2.0) && my >= (weapon_c3 + 5*weapon_c4 - textHeight()) && my <= (weapon_c3 + 5*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[5].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "JACK HAMMER") ; tanks1.weapon[cl1] = 25 ; cl1++ ; weapon_p2[5] = true ;
				chance = 2 ; success++ ;
			}
			else{
				weapon_list2[5].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "JACK HAMMER") ; tanks2.weapon[cl2] = 25 ; cl2++ ; weapon_p2[5] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[6] == false && mx <= (weapon_c2 + textWidth("HAIL STORM")/2.0) && mx >= (weapon_c2 - textWidth("HAIL STORM")/2.0) && my >= (weapon_c3 + 6*weapon_c4 - textHeight()) && my <= (weapon_c3 + 6*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[6].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "HAIL STORM") ; tanks1.weapon[cl1] = 26 ; cl1++ ; weapon_p2[6] = true ;
				chance = 2 ; success++ ;
			}
			else{
				weapon_list2[6].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "HAIL STORM") ; tanks2.weapon[cl2] = 26 ; cl2++ ; weapon_p2[6] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[7] == false && mx <= (weapon_c2 + textWidth("FLASH BLAST")/2.0) && mx >= (weapon_c2 - textWidth("FLASH BLAST")/2.0) && my >= (weapon_c3 + 7*weapon_c4 - textHeight()) && my <= (weapon_c3 + 7*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[7].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "FLASH BLAST") ; tanks1.weapon[cl1] = 27 ; cl1++ ; weapon_p2[7] = true ;
				chance = 2 ; success++ ;
			}
			else {
				weapon_list2[7].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "FLASH BLAST") ; tanks2.weapon[cl2] = 27 ; cl2++ ; weapon_p2[7] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[8] == false && mx <= (weapon_c2 + textWidth("SONIC BLAST")/2.0) && mx >= (weapon_c2 - textWidth("SONIC BLAST")/2.0) && my >= (weapon_c3 + 8*weapon_c4 - textHeight()) && my <= (weapon_c3 + 8*weapon_c4 + textHeight()))
			if(chance == 1) {
				weapon_list2[8].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "SONIC BLAST") ; tanks1.weapon[cl1] = 28 ; cl1++ ; weapon_p2[8] = true ;
				chance = 2 ; success++ ;
			}
			else{
				weapon_list2[8].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "SONIC BLAST") ; tanks2.weapon[cl2] = 28 ; cl2++ ; weapon_p2[8] = true ;
				chance = 1 ; success++ ;
			}
		else if(weapon_p2[9] == false && mx <= (weapon_c2 + textWidth("SUPER NOVA")/2.0) && mx >= (weapon_c2 - textWidth("SUPER NOVA")/2.0) && my >= (weapon_c3 + 9*weapon_c4 - textHeight()) && my <= (weapon_c3 + 9*weapon_c4 + textHeight())) {
			if(chance == 1){
				weapon_list2[9].reset(weapon_c1 - weapon_c5 , weapon_c3 + cl1*weapon_c4 , "SUPER NOVA") ; tanks1.weapon[cl1] = 29 ; cl1++ ; weapon_p2[9] = true ;
				chance = 2 ; success++ ;
			}
			else{
				weapon_list2[9].reset(weapon_c2 + weapon_c5 , weapon_c3 + cl2*weapon_c4 , "SUPER NOVA") ; tanks2.weapon[cl2] = 29 ; cl2++ ; weapon_p2[9] = true ;
				chance = 1 ; success++ ;
			}
		}
	} 
	for(int tpp = 0 ; tpp < 10 ; tpp++) {
		weapon_list1[tpp].hide() ;
		weapon_list2[tpp].hide() ;
	}
	randomize_list.hide() ;
	zz.hide() ;
	weapon_heading.hide() ;
	
	if(game == 1){
		info_wpn1.hide();
		info_wpn2.hide();
		info_wpn3.hide();
	}	
	
	//ground
	float ground_g = 128 ;
	Rectangle r(500 , 570 , 1000 , 60);
	for(int ground_c = 570 ; ground_c <=600 ; ground_c++) {
		r.reset(500 , ground_c , 1000 , 60) ;
		r.setFill(true) ;
		r.setColor(COLOR(0 , ground_g*(1.0 - ((ground_c - 570)/30.0)) , 0) , true) ;
		r.imprint() ;
		r.hide() ;
	}
	int wall1H = 200 , wall2H = 200 , wall1x = 350 , wall2x = 650 ;
	Rectangle w1(wall1x , 540 - wall1H / 2 , 40 , wall1H) ;
	w1.setFill(true) ;
	w1.setColor(COLOR(110 , 110 , 110) , true) ;
	w1.imprint() ;
	Rectangle w2(wall2x , 540 - wall2H / 2 , 40 , wall2H) ;
	w2.setFill(true) ;
	w2.setColor(COLOR(110 , 110 , 110) , true) ;
	w2.imprint() ;
	int c1x = 50 , c1y = 200 , c2x = 950 , c2y = 200 , ccx = 500 , ccy = 490 , wrad = 40 ;
	Circle wh1;
	wh1.setFill(true) ;
	for(int tt = 0 ; tt < 7 ; tt++ , wrad = wrad - 3) {
		wh1.reset(c1x , c1y , wrad) ;
		wh1.setColor(COLOR(100 * (1.0 - tt/7.0) , 100 * (1.0 - tt/7.0) , 100 * (1.0 - tt/7.0)) , true) ;
		wh1.imprint() ;
		wh1.reset(c2x , c2y , wrad) ;
		wh1.setColor(COLOR(100 * (1.0 - tt/7.0) , 100 * (1.0 - tt/7.0) , 100 * (1.0 - tt/7.0)) , true) ;
		wh1.imprint() ;
		wh1.reset(ccx , ccy , wrad) ;
		wh1.setColor(COLOR(100 * (1.0 - tt/7.0) , 100 * (1.0 - tt/7.0) , 100 * (1.0 - tt/7.0)) , true) ;
		wh1.imprint() ;
	}
	wrad = 40 ;
	
	//volley number
	Text volley(485 , 20 , "Volley number : ") ;
	Text number_volley(540 , 20 , " ") ;
	volley.setFill(true) ;
	volley.setColor(COLOR(255 , 255 , 255) , true) ;
	
	//tank left
	Rectangle barrel1(40 + tankW/4, 540 - tankH - tankW/4, tankW*0.707, 5);
	barrel1.setFill(true);
	barrel1.setColor(COLOR(100,100,100),true);
	barrel1.rotate(-PI/4);
	Circle top1(40, 520 - tankH/2, 20);
	top1.setFill(true);
	top1.setColor(COLOR(0,0,0),true);
	Rectangle tank1(40 , 520 , tankW , tankH) ;
	tank1.setFill(true) ;
	tank1.setColor(COLOR(180 , 0 , 0) , true) ;
	tanks1.x = 40 ; tanks1.y = 520 ;
	Text t_left(20 , 20 , "0") ;
	t_left.setFill(true) ;
	t_left.setColor(COLOR(0 , 0 , 0) , true) ;
	Text m1_l(20 , 60 , "LEFT") ;
	m1_l.setFill(true) ;
	m1_l.setColor(COLOR(255 , 255 , 255) , true) ;
	m1_l.imprint() ;
	Rectangle b1_l(20 , 60 , textWidth("LEFT") + 10 , textHeight() + 10) ;
	b1_l.setFill(false) ;
	b1_l.setColor(COLOR(255 , 255 , 255) , true) ;
	b1_l.imprint() ;
	Text m1_r(100 , 60 , "RIGHT") ;
	m1_r.setFill(true) ;
	m1_r.setColor(COLOR(255 , 255 , 255) , true) ;
	m1_r.imprint() ;
	Rectangle b1_r(100 , 60 , textWidth("RIGHT") + 10 , textHeight() + 10) ;
	b1_r.setFill(false) ;
	b1_r.setColor(COLOR(255 , 255 , 255) , true) ;
	b1_r.imprint() ;
	Text movesrem1(100 , 100 , "MOVES REMAINING : ") ;
	movesrem1.setFill(true) ;
	movesrem1.setColor(COLOR(255 , 255 , 255) , true) ;
	movesrem1.imprint() ;
	Text moves1(110 + textWidth("MOVES REMAINING : ") / 2 , 100 , "3") ;
	moves1.setFill(true) ;
	moves1.setColor(COLOR(255 , 255 , 255) , true) ;
	Text wlist1(200 , 150 , "WEAPONS") ;
	wlist1.setFill(true) ;
	wlist1.setColor(COLOR(255 , 255 , 255) , true) ;
	wlist1.imprint() ;
	int move1 = 0 ;
	
	//tank right
	Rectangle barrel2(960 - tankW/4, 540 - tankH - tankW/4, tankW*0.707, 5);
	barrel2.setFill(true);
	barrel2.setColor(COLOR(100,100,100),true);
	barrel2.rotate(PI/4);
	Circle top2(960, 520 - tankH/2, 20);
	top2.setFill(true);
	top2.setColor(COLOR(0,0,0),true);
	Rectangle tank2(960 , 520 , tankW , tankH) ;
	tank2.setFill(true) ;
	tank2.setColor(COLOR(0 , 0 , 180) , true) ;	
	tanks2.x = 960 ; tanks2.y = 520 ;
	Text t_right(980 , 20 , "0") ;
	t_right.setFill(true) ;
	t_right.setColor(COLOR(0 , 0 , 0) , true) ;
	Text m2_l(900 , 60 , "LEFT") ;
	m2_l.setFill(true) ;
	m2_l.setColor(COLOR(255 , 255 , 255) , true) ;
	m2_l.imprint() ;
	Rectangle b2_l(900 , 60 , textWidth("LEFT") + 10 , textHeight() + 10) ;
	b2_l.setFill(false) ;
	b2_l.setColor(COLOR(255 , 255 , 255) , true) ;
	b2_l.imprint() ;
	Text m2_r(970 , 60 , "RIGHT") ;
	m2_r.setFill(true) ;
	m2_r.setColor(COLOR(255 , 255 , 255) , true) ;
	m2_r.imprint() ;
	Rectangle b2_r(970 , 60 , textWidth("RIGHT") + 10 , textHeight() + 10) ;
	b2_r.setFill(false) ;
	b2_r.setColor(COLOR(255 , 255 , 255) , true) ;
	b2_r.imprint() ;
	Text movesrem2(900 , 100 , "MOVES REMAINING : ") ;
	movesrem2.setFill(true) ;
	movesrem2.setColor(COLOR(255 , 255 , 255) , true) ;
	movesrem2.imprint() ;
	Text moves2(910 + textWidth("MOVES REMAINING : ") / 2 , 100 , "3") ;
	moves2.setFill(true) ;
	moves2.setColor(COLOR(255 , 255 , 255) , true) ;
	Text wlist2(800 , 150 , "WEAPONS") ;
	wlist2.setFill(true) ;
	wlist2.setColor(COLOR(255 , 255 , 255) , true) ;
	wlist2.imprint() ;
	int move2 = 0 ;
	
	//quit button
	Text quitg(500 , 50 , "QUIT") ;
	quitg.setFill(true) ;
	quitg.setColor(COLOR(255 , 255 , 255) , true) ;
	Rectangle quitg_r(500 , 50 , 10 + textWidth("QUIT") , 10 + textHeight()) ;
	quitg_r.setColor(COLOR(255 , 255 , 255) , true) ;
	
	if(game == 1){
		Text info_tank1(10 + textWidth("This is Player 1's tank.")/2, 440, "This is Player 1's tank.");
		info_tank1.setColor(COLOR(0,0,0),true);
		Text info_tank2(canvasWidth - 10 - textWidth("This is Player 2's tank.")/2, 440, "This is Player 2's tank.");
		info_tank2.setColor(COLOR(0,0,0),true);
		wait(2);
		info_tank1.hide();
		info_tank2.hide();
	}
	
	
	for(int counter_1 = 1 ; counter_1 <= 10 ; counter_1++) {
	number_volley.reset(540 , 20 , counter_1) ;
	number_volley.setFill(true) ;
	number_volley.setColor(COLOR(255 , 255 , 255) , true) ;
	
	//instructions
	if(game == 1 && counter_1 == 1 ){
		for(int i = 0; i < 12 ; i++){
			info1[i].setColor(COLOR(255,255,255),true);
		}
		info1[0].reset(canvasWidth/2,110,"Click a Weapon to select it");
		info1[1].reset(canvasWidth/2,140,"Each weapon can be used only once.");
		info1[2].reset(canvasWidth/2,170,"Before using move commands,");
		info1[3].reset(canvasWidth/2,200,"Please select a weapon first.");
		info1[4].reset(canvasWidth/2,230,"Use Left or Right to move.");
		info1[5].reset(canvasWidth/2,260,"Only one move is allowed per turn.");
	}

	//Projectile1
	Text wpnlst[10] ;
	Rectangle wpnrct[10] ;
	for(int k = 0 ; k < 10 ; k++) {
		if(tanks1.isused[k] == false) {
			wpnlst[k].reset(200 , 200 + 20 * k , wpns(tanks1.weapon[k])) ;
			wpnlst[k].setFill(true) ;
			wpnlst[k].setColor(COLOR(255 , 255 , 255) , true) ;
		}
		wpnrct[k].reset(200 , 200 + 20 * k , 4 + textWidth("HOMING MISSILE") , textHeight() + 4) ;
		wpnrct[k].setFill(false) ;
		wpnrct[k].setColor(COLOR(255 , 255 , 255) , true) ;
	}
	while(true) {
		int click_v = getClick() ;
		int click_x = click_v/65536 ;
		int click_y = click_v%65536 ;
		int m = wpcd1(click_x , click_y) ;
		if(m == (-2)) return 0 ;
		else if(m == (-1)){
			Text warning(canvasWidth/2, 200, "Please select a weapon first.");
			warning.setColor(COLOR(255,255,255),true);
			int i = getClick();
			i++ ;
			warning.hide();
			continue ;
		}	
		else if(tanks1.isused[m] == false) {
			wpnactive1 = tanks1.weapon[m] ;
			tanks1.isused[m] = true ;
			wpnlst[m].hide() ;
			break ;
		}
	}
	for(int k = 0 ; k < 10 ; k++) {
		if(tanks1.isused[k] == false) {
			wpnlst[k].hide() ;
		}
		wpnrct[k].hide() ;
	}
	
	if(game == 1 && counter_1 == 1){
		for(int i=0; i<6; i++){
			info1[i].hide();
		}
		
		info1[6].reset(canvasWidth/2, 110, "Click to shoot projectile.");
		info1[7].reset(canvasWidth/2, 140, "Distance from Tank decides velocity.");
		info1[8].reset(canvasWidth/2, 170, "There is a maximum velocity limit.");
		info1[9].reset(canvasWidth/2, 200, "A dot will represent your last click.");
		info1[10].reset(canvasWidth/2, 250, "Shoot into central wormhole to ");
		info1[11].reset(canvasWidth/2, 280, "hit your opponent from his wormhole.");
	}
	
	int click_v = getClick() ;
	int click_x = click_v/65536 ;
	int click_y = click_v%65536 ;
	LastClick1.reset(click_x, click_y, 2);
	if(click_x < 25 + textWidth("LEFT") / 2 && click_x > 15 - textWidth("LEFT") && click_y > 55 - textHeight() / 2 && click_y < 65 + textHeight() / 2) {
		if(move1 < 3) {
			if(tanks1.x >= tankW/2 + 50) {
				repeat(50) {
					tank1.move(-1 , 0) ;
					top1.move(-1 , 0) ;
					barrel1.move(-1 , 0) ;
					wait(0.01) ;
				}
				move1++ ;
				tanks1.x = tanks1.x - 50 ;
				moves1.reset(110 + textWidth("MOVES REMAINING : ") / 2 , 100 , (3 - move1)) ;
				click_v = getClick() ;
				click_x = click_v/65536 ;
				click_y = click_v%65536 ;
				LastClick1.reset(click_x, click_y, 2);
			}
		}
	}
	else if(click_x < 105 + textWidth("RIGHT") / 2 && click_x > 95 - textWidth("RIGHT") && click_y > 55 - textHeight() / 2 && click_y < 65 + textHeight() / 2) {
		if(move1 < 3) {
			repeat(50) {
				tank1.move(1 , 0) ;
				top1.move(1 , 0) ;
				barrel1.move(1 , 0) ;
				wait(0.01) ;
			}
			move1++ ;
			tanks1.x = tanks1.x + 50 ;
			moves1.reset(110 + textWidth("MOVES REMAINING : ") / 2 , 100 , (3 - move1)) ;
			click_v = getClick() ;
			click_x = click_v/65536 ;
			click_y = click_v%65536 ;
			LastClick1.reset(click_x, click_y, 2);
		}
	}
	else if(click_x < 505 + textWidth("QUIT") / 2 && click_x > 495 - textWidth("QUIT") && click_y > 45 - textHeight() / 2 && click_y < 55 + textHeight() / 2) {
		return 0 ;
	}
	if(game == 1 && counter_1 == 1){
		info1[6].hide();
		info1[7].hide();
		info1[8].hide();
		info1[9].hide();
		info1[10].hide();
		info1[11].hide();
	}				

	Circle proj((tanks1.x + tankW/2) , (tanks1.y - tankH/2 - tankW/2) , 5) ;
	proj.setFill(true) ;
	proj.setColor(COLOR(160 , 0 , 0) , true) ;
	float velocity_x , velocity_y ;
	
	float dist_x = click_x - (tanks1.x + tankW/2) ; //positive
	float dist_y = (tanks1.y - tankH/2) - click_y ;		//positive
	
	if(dist_x < 200 && dist_x > -200)  // if u click too far then it won't work as expected
		velocity_x = velocity_k * dist_x ;
	else
		velocity_x = velocity_k * 200 ;
		
	if(dist_y < 200 && dist_y > -200)  // if u click too far then it won't work as expected
		velocity_y = -velocity_k * dist_y ;
	else
		velocity_y = -velocity_k * 200 ;
	
	float track = tanks1.y + tankH/2 + 1 ;
	float proj_x = (tanks1.x + tankW/2) , proj_y = (tanks1.y - tankH/2 - tankW/2) ;
	int distance = 100 ;
	bool overshoot = false ;
	bool hit = false ;
	bool pass = false ;
	
	while(proj_y < track) {
		if(wpnactive1 == 15) {
			proj.hide() ;
			hit = true ;
			proj_x = tanks2.x - tankW / 2 ; proj_y = tanks2.y - tankH / 2 ;
			exp_l1.reset(tanks1.x + tankW / 2 , tanks1.y - tankH / 2 , tanks2.x - tankW / 2 , tanks2.y - tankH / 2) ;
			exp_l1.setFill(true) ;
			for(int cll = 0 ; cll < 200 ; cll++) {
				exp_l1.setColor(COLOR(0 , 255 , 255 * (1.0 - cll / 267.0)) , true) ;
				wait(0.01) ;
			}
			exp_l1.hide() ;
			break ;
		}
		proj.move(velocity_x , velocity_y) ;
		proj_x = proj_x + velocity_x ;
		proj_y = proj_y + velocity_y ;
		velocity_y = velocity_y + g ;
		wait(0.001) ;
		
		//if ball overshoots the screen then no points
		if(proj_x > 1000 || proj_x < 0) {
			overshoot = true ;
			break;
		}
		
		//if ball hits target precisely then full points
		if(proj_x < (tanks2.x + tankW/2) && proj_x > (tanks2.x - tankW/2))
			if(proj_y > (tanks2.y - tankH/2) && proj_y < (tanks2.y + tankH/2)) {
				hit = true ;
				break ;
			}
		if(proj_y > (tanks2.y - tankH/2) && proj_y < (tanks2.y + tankH/2))
			if(proj_x > (tanks2.x - tankW/2) && proj_x < (tanks2.x + tankW/2)) {
				hit = true ;
				break ;
			}
		if(sqrt((proj_x - tanks2.x) * (proj_x - tanks2.x) + (proj_y - tanks2.y + tankW/2)*(proj_y - tanks2.y + tankW/2)) <= 20) {
			hit = true ;
			break ;
		}
		//hits left wall
		if(proj_x < (wall1x + 40/2) && proj_x > (wall1x - 40/2))
			if(proj_y > (540 - wall1H) && proj_y < 540) {
				break ;
			}
		if(proj_y > (540 - wall1H) && proj_y < 540)
			if(proj_x > (wall1x - 40/2) && proj_x < (wall1x + 40/2)) {
				break ;
			}
		//hits right wall
		if(proj_x < (wall2x + 40/2) && proj_x > (wall2x - 40/2))
			if(proj_y > (540 - wall1H) && proj_y < 540) {
				break ;
			}
		if(proj_y > (540 - wall2H) && proj_y < 540)
			if(proj_x > (wall2x - 40/2) && proj_x < (wall2x + 40/2)) {
				break ;
			}
		//wormhole1
		if(sqrt(pow((proj_x - c1x) , 2) + pow((proj_y - c1y) , 2)) < wrad * 1.0) {
			overshoot = true ;
			break ;
		}
		//wormhole2
		if(sqrt(pow((proj_x - c2x) , 2) + pow((proj_y - c2y) , 2)) < wrad * 1.0 && pass == false) {
			overshoot = true ;
			break ;
		}
		
		//warmhole center
		if(sqrt(pow((proj_x - ccx) , 2) + pow((proj_y - ccy) , 2)) < wrad * 1.0) {
			pass = true ;
			proj.moveTo(c2x , c2y) ;
			proj_x = c2x ; proj_y = c2y ;
			if(velocity_x > 0)
				velocity_x = -1 * velocity_x ;
		}
	}
	proj.hide() ;
	//explosion1
	float smultiplier = 1.0 , dmultiplier = 1.0 ;
	if(overshoot == false) {
		//WORM
		if(wpnactive1 == 10) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 128 , 0) , true) ;
			
			for(int i = 0 ; i < 15 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 14.0) , 128 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 14 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 14.0) , 128 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 0.6 ;
		}
		//ZAPPER
		else if(wpnactive1 == 11) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 64 , 64) , true) ;
			for(int i = 0 ; i < 20 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 19 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.2 ;
			smultiplier = 0.4 ;
		}
		//PILE DRIVER
		else if(wpnactive1 == 12) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 0 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.5 ;
		}
		//BIG SHOT
		else if(wpnactive1 == 13) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 64 , 64) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.5 ;
			smultiplier = 0.6 ;
		}
		//SPIDER
		else if(wpnactive1 == 14) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(192 , 192 , 192) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(192 * (1.0 - i / 24.0) , 192 * (1.0 - i / 24.0) , 192 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 1.6 ;
		}
		//GAMMA BLASTER
		else if(wpnactive1 == 15) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 255 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.3 ;
		}
		//HOMING MISSILE
		else if(wpnactive1 == 16) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 128 , 64) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 2.0 ;
			smultiplier = 0.6 ;
		}
		//HEATSEEKER
		else if(wpnactive1 == 17) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 128 , 64) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.5 ;
			smultiplier = 0.6 ;
		}
		//FIREBALL
		else if(wpnactive1 == 18) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 128 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.5 ;
			smultiplier = 2.0 ;
		}
		//CRAZY IVAN
		else if(wpnactive1 == 19) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(0 , 128 , 192) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR((234 * i) % 211 , (209 * i) % 192 , (251 * i) % 227) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR((234 * i) % 211 , (209 * i) % 192 , (251 * i) % 227) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 0.8 ;
		}
		//GROUND HOG
		else if(wpnactive1 == 20) {
			exp_r1.reset(proj_x , proj_y , 10 , 1) ;
			exp_r1.setFill(true) ;
			exp_r1.setColor(COLOR(128 , 64 , 64) , true) ;
			for(int i = 0 ; i < 200 ; i++) {
				exp_r1.rotate(1) ;
				exp_r1.scale(1.01) ;
				exp_r1.setColor(COLOR(128 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0)) , true) ;
				wait(0.002) ;
			}
			for(int i = 199 ; i >=0 ; i--) {
				exp_r1.rotate(1) ;
				exp_r1.scale(1 / 1.01) ;
				exp_r1.setColor(COLOR(128 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0)) , true) ;
				wait(0.002) ;
			}
			exp_r1.hide() ;
			dmultiplier = 1.8 ;
			smultiplier = 1.6 ;
		}
		//SNIPER RIFLE
		else if(wpnactive1 == 21) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.4 ;
			smultiplier = 1.0 ;
		}
		//FIRE CRACKER
		else if(wpnactive1 == 22) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 32 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 32 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 32 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 0.8 ;
		}
		//CHAIN REACTION
		else if(wpnactive1 == 23) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(235 , 143 , 5) , true) ;
			float l = 0 , m = 0 , n = 0 ;
			repeat(7) {
				if(l == 0) {
					m = 0 ; n = 0 ;
				}
				else if(l == 1) {
					m = 1 ; n = 0 ;
				}
				else if(l == 2) {
					m = -1 ; n = 0 ;
				}
				else if(l == 3) {
					m = -0.5 , n = -1 ;
				}
				else if(l == 4) {
					m = 0.5 , n = -1 ;
				}
				else if(l == 5) {
					m = -0.5 ; n = 1 ;
				}
				else if(l == 6) {
					m = 0.5 ; n = 1 ;
				}
				exp_1.reset(proj_x + 20 * m , proj_y + 20 * n , 2) ;
				l++ ;
				for(int i = 0 ; i < 20 ; i++) {
					exp_1.scale(1.11) ;
					exp_1.setColor(COLOR(235 * (1.0 - i / 19.0) , 143 * (1.0 - i / 19.0) , 5 * (1.0 - i / 19.0)) , true) ;
					wait(0.005) ;
				}
				for(int i = 19 ; i >=0 ; i--) {
					exp_1.scale(1.0/1.11) ;
					exp_1.setColor(COLOR(235 * (1.0 - i / 19.0) , 143 * (1.0 - i / 19.0) , 5 * (1.0 - i / 19.0)) , true) ;
					wait(0.005) ;
				}
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 2.6 ;
		}
		//NAPALM
		else if(wpnactive1 == 24) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(237 , 185 , 3) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(237 * (1.0 - i / 24.0) , 185 * (1.0 - i / 24.0) , 3 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(237 * (1.0 - i / 24.0) , 185 * (1.0 - i / 24.0) , 3 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 1.6 ;
		}
		//JACK HAMMER
		else if(wpnactive1 == 25) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(64 , 0 , 0) , true) ;
			repeat(3) {
				for(int i = 0 ; i < 15 ; i++) {
					exp_1.scale(1.11) ;
					exp_1.setColor(COLOR(64 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
					wait(0.005) ;
				}
				for(int i = 14 ; i >=0 ; i--) {
					exp_1.scale(1.0/1.11) ;
					exp_1.setColor(COLOR(64 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
					wait(0.005) ;
				}
				exp_1.reset(proj_x , proj_y , 3) ;
				int i = 0 ;
				repeat(75) {
					exp_1.move(0 , -2 * (1.0 - i/75.0)) ;
					wait(0.01) ;
					i++ ;
				}
				i = 25 ;
				repeat(25) {
					exp_1.move(0 , 6 * (1.0 - i/25.0)) ;
					wait(0.008) ;
					i-- ;
				}
				exp_1.reset(proj_x , proj_y , 2) ;
			}		
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.5 ;
		}
		//HAIL STORM
		else if(wpnactive1 == 26) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(43 , 149 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(43 * (1.0 - i / 24.0) , 149 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(43 * (1.0 - i / 24.0) , 149 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 1.6 ;
		}
		//FLASH BLAST
		else if(wpnactive1 == 27) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(0 , 0 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				if(i % 2 == 0)
					exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
				else
					exp_1.setColor(COLOR(0 , 0 , 0) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				if(i % 2 == 0)
					exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
				else
					exp_1.setColor(COLOR(0 , 0 , 0) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.6 ;
		}
		//SONIC BLAST
		else if(wpnactive1 == 28) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(3 , 103 , 252) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(3 * (1.0 - i / 24.0) , 103 * (1.0 - i / 24.0) , 252 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(3 * (1.0 - i / 24.0) , 103 * (1.0 - i / 24.0) , 252 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.1 ;
			smultiplier = 2.5 ;
		}
		//SUPER NOVA
		else if(wpnactive1 == 29) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.2 ;
			smultiplier = 2.0 ;
		}
	}	
	if(overshoot == true)
		distance = 100 ;
	else if(hit == true)
		distance = 0 ;
	else
		distance = abs(proj_x - tanks2.x) ;
	
	if(distance <= dmultiplier * 100)
		tanks1.score = tanks1.score + (dmultiplier * 100 - distance) * smultiplier  ;
	
	t_left.reset(20 , 20 , tanks1.score) ;
	t_left.setColor(COLOR(255 , 255 , 255) , true) ;
	
	//Projectile2
	for(int k = 0 ; k < 10 ; k++) {
		if(tanks2.isused[k] == false) {
			wpnlst[k].reset(800 , 200 + 20 * k , wpns(tanks2.weapon[k])) ;
			wpnlst[k].setFill(true) ;
			wpnlst[k].setColor(COLOR(255 , 255 , 255) , true) ;
		}
		wpnrct[k].reset(800 , 200 + 20 * k , 4 + textWidth("HOMING MISSILE") , textHeight() + 4) ;
		wpnrct[k].setFill(false) ;
		wpnrct[k].setColor(COLOR(255 , 255 , 255) , true) ;
	}
	while(true) {
		int click_v = getClick() ;
		int click_x = click_v/65536 ;
		int click_y = click_v%65536 ;
		int m = wpcd2(click_x , click_y) ;
		if(m == (-2)) return 0 ;
		else if(m == (-1)){
			Text warning(canvasWidth/2, 200, "Please select a weapon first.");
			warning.setColor(COLOR(255,255,255),true);
			int i = getClick();
			i++ ;
			warning.hide();
			continue ;	
		}
		else if(tanks2.isused[m] == false) {
			wpnactive2 = tanks2.weapon[m] ;
			tanks2.isused[m] = true ;
			wpnlst[m].hide() ;
			break ;
		}
	}
	for(int k = 0 ; k < 10 ; k++) {
		if(tanks2.isused[k] == false) {
			wpnlst[k].hide() ;
		}
		wpnrct[k].hide() ;
	}
	click_v = getClick() ;
	click_x = click_v/65536 ;
	click_y = click_v%65536 ;
	LastClick2.reset(click_x, click_y, 2);
	if(click_x < 905 + textWidth("LEFT") / 2 && click_x > 895 - textWidth("LEFT") && click_y > 55 - textHeight() / 2 && click_y < 65 + textHeight() / 2) {
		if(move2 < 3) {
			repeat(50) {
				tank2.move(-1 , 0) ;
				top2.move(-1 , 0) ;
				barrel2.move(-1 , 0) ;
				wait(0.01) ;
			}
			move2++ ;
			tanks2.x = tanks2.x - 50 ;
			moves2.reset(910 + textWidth("MOVES REMAINING : ") / 2 , 100 , (3 - move2)) ;
			click_v = getClick() ;
			click_x = click_v/65536 ;
			click_y = click_v%65536 ;
			LastClick2.reset(click_x, click_y, 2);
		}
	}
	else if(click_x < 975 + textWidth("RIGHT") / 2 && click_x > 965 - textWidth("RIGHT") && click_y > 55 - textHeight() / 2 && click_y < 65 + textHeight() / 2) {
		if(move2 < 3) {
			if(tanks2.x <= 1000 - (tankW/2 + 50)) {
				repeat(50) {
					tank2.move(1 , 0) ;
					top2.move(1 , 0) ;
					barrel2.move(1 , 0) ;
					wait(0.01) ;
				}
				move2++ ;
				tanks2.x = tanks2.x + 50 ;
				moves2.reset(910 + textWidth("MOVES REMAINING : ") / 2 , 100 , (3 - move2)) ;
				click_v = getClick() ;
				click_x = click_v/65536 ;
				click_y = click_v%65536 ;
				LastClick2.reset(click_x, click_y, 2);
			}
		}
	}
	else if(click_x < 505 + textWidth("QUIT") / 2 && click_x > 495 - textWidth("QUIT") && click_y > 45 - textHeight() / 2 && click_y < 55 + textHeight() / 2) {
		return 0 ;
	}
	
	Circle proj2((tanks2.x - tankW/2) , (tanks2.y - tankH/2 - tankW/2) , 5) ;
	proj2.setFill(true) ;
	proj2.setColor(COLOR(160 , 0 , 0) , true) ;
	velocity_x = velocity_y = 0 ;
	
	dist_x = (tanks2.x - tankW/2) - click_x ; 		//positive
	dist_y = (tanks2.y - tankH/2) - click_y ;		//positive
	
	if(dist_x < 200 && dist_x > -200)  // if u click too far then it won't work as expected
		velocity_x = velocity_k * dist_x ;
	else
		velocity_x = velocity_k * 200 ;
		
	if(dist_y < 200 && dist_y > -200)  // if u click too far then it won't work as expected
		velocity_y = -velocity_k * dist_y ;
	else
		velocity_y = -velocity_k * 200 ;
	
	track = tanks2.y + tankH/2 + 1 ;
	proj_x = (tanks2.x - tankW/2) , proj_y = (tanks2.y - tankH/2 - tankW/2) ;
	distance = 100 ;
	overshoot = false ;
	hit = false ;
	pass = false ;
	
	while(proj_y < track) {
		if(wpnactive2 == 15) {
			proj2.hide() ;
			hit = true ;
			proj_x = tanks1.x + tankW / 2 ; proj_y = tanks1.y - tankH / 2 ;
			exp_l1.reset(tanks1.x + tankW / 2 , tanks1.y - tankH / 2 , tanks2.x - tankW / 2 , tanks2.y - tankH / 2) ;
			exp_l1.setFill(true) ;
			for(int cll = 0 ; cll < 200 ; cll++) {
				exp_l1.setColor(COLOR(0 , 255 , 255 * (1.0 - cll / 267.0)) , true) ;
				wait(0.01) ;
			}
			exp_l1.hide() ;
			break ;
		}
		proj2.move(-velocity_x , velocity_y) ;
		proj_x = proj_x - velocity_x ;
		proj_y = proj_y + velocity_y ;
		velocity_y = velocity_y + g ;
		wait(0.001) ;
		
		//if ball overshoots the screen then no points
		if(proj_x < 0 || proj_x > 1000) {
			overshoot = true ;
			break;
		}
		
		//if ball hits target precisely then full points
		if(proj_x > (tanks1.x - tankW/2) && proj_x < (tanks1.x + tankW/2))
			if(proj_y > (tanks1.y - tankH/2) && proj_y < (tanks1.y + tankH/2)) {
				hit = true ;
				break ;
			}
		if(proj_y > (tanks1.y - tankH/2) && proj_y < (tanks1.y + tankH/2))
			if(proj_x < (tanks1.x + tankH/2) && proj_x > (tanks1.x - tankW/2)) {
				hit = true ;
				break ;
			}
		if(sqrt((proj_x - tanks1.x) * (proj_x - tanks1.x) + (proj_y - tanks1.y + tankW/2)*(proj_y - tanks1.y + tankW/2)) <= 20) {
			hit = true ;
			break ;
		}
		//hits left wall
		if(proj_x < (wall1x + 40/2) && proj_x > (wall1x - 40/2))
			if(proj_y > (540 - wall1H) && proj_y < 540) {
				break ;
			}
		if(proj_y > (540 - wall1H) && proj_y < 540)
			if(proj_x > (wall1x - 40/2) && proj_x < (wall1x + 40/2)) {
				break ;
			}
		//hits right wall
		if(proj_x < (wall2x + 40/2) && proj_x > (wall2x - 40/2))
			if(proj_y > (540 - wall1H) && proj_y < 540) {
				break ;
			}
		if(proj_y > (540 - wall2H) && proj_y < 540)
			if(proj_x > (wall2x - 40/2) && proj_x < (wall2x + 40/2)) {
				break ;
			}
		//wormhole2
		if(sqrt(pow((proj_x - c2x) , 2) + pow((proj_y - c2y) , 2)) < wrad * 1.0) {
			overshoot = true ;
			break ;
		}
		
		//wormhole1
		if(sqrt(pow((proj_x - c1x) , 2) + pow((proj_y - c1y) , 2)) < wrad * 1.0 && pass == false) {
			overshoot = true ;
			break ;
		}
		//warmhole center
		if(sqrt(pow((proj_x - ccx) , 2) + pow((proj_y - ccy) , 2)) < wrad * 1.0) {
			pass = true ;
			proj2.moveTo(c1x , c1y) ;
			proj_x = c1x ; proj_y = c1y ;
			if(velocity_x > 0)
				velocity_x = -1 * velocity_x ;
		}
	}
	proj2.hide() ;
	//explosion2
	if(overshoot == false) {
		//WORM
		if(wpnactive2 == 10) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 128 , 0) , true) ;
			
			for(int i = 0 ; i < 15 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 14.0) , 128 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 14 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 14.0) , 128 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 0.6 ;
		}
		//ZAPPER
		else if(wpnactive2 == 11) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 64 , 64) , true) ;
			for(int i = 0 ; i < 20 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 19 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0) , 64 * (1.0 - i / 19.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.2 ;
			smultiplier = 0.4 ;
		}
		//PILE DRIVER
		else if(wpnactive2 == 12) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 0 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.5 ;
		}
		//BIG SHOT
		else if(wpnactive2 == 13) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 64 , 64) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.5 ;
			smultiplier = 0.6 ;
		}
		//SPIDER
		else if(wpnactive2 == 14) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(192 , 192 , 192) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(192 * (1.0 - i / 24.0) , 192 * (1.0 - i / 24.0) , 192 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 1.6 ;
		}
		//GAMMA BLASTER
		else if(wpnactive2 == 15) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 255 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.3 ;
		}
		//HOMING MISSILE
		else if(wpnactive2 == 16) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 128 , 64) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 2.0 ;
			smultiplier = 0.6 ;
		}
		//HEATSEEKER
		else if(wpnactive2 == 17) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(128 , 128 , 64) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(128 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 64 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.5 ;
			smultiplier = 0.6 ;
		}
		//FIREBALL
		else if(wpnactive2 == 18) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 128 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 128 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.5 ;
			smultiplier = 2.0 ;
		}
		//CRAZY IVAN
		else if(wpnactive2 == 19) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(0 , 128 , 192) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR((234 * i) % 211 , (209 * i) % 192 , (251 * i) % 227) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR((234 * i) % 211 , (209 * i) % 192 , (251 * i) % 227) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 0.8 ;
		}
		//GROUND HOG
		else if(wpnactive2 == 20) {
			exp_r1.reset(proj_x , proj_y , 10 , 1) ;
			exp_r1.setFill(true) ;
			exp_r1.setColor(COLOR(128 , 64 , 64) , true) ;
			for(int i = 0 ; i < 200 ; i++) {
				exp_r1.rotate(1) ;
				exp_r1.scale(1.01) ;
				exp_r1.setColor(COLOR(128 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0)) , true) ;
				wait(0.002) ;
			}
			for(int i = 199 ; i >=0 ; i--) {
				exp_r1.rotate(1) ;
				exp_r1.scale(1 / 1.01) ;
				exp_r1.setColor(COLOR(128 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0) , 64 * (1.0 - i / 400.0)) , true) ;
				wait(0.002) ;
			}
			exp_r1.hide() ;
			dmultiplier = 1.8 ;
			smultiplier = 1.6 ;
		}
		//SNIPER RIFLE
		else if(wpnactive2 == 21) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.4 ;
			smultiplier = 1.0 ;
		}
		//FIRE CRACKER
		else if(wpnactive2 == 22) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 32 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 32 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 32 * (1.0 - i / 24.0) , 0 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 0.8 ;
			smultiplier = 0.8 ;
		}
		//CHAIN REACTION
		else if(wpnactive2 == 23) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(235 , 143 , 5) , true) ;
			float l = 0 , m = 0 , n = 0 ;
			repeat(7) {
				if(l == 0) {
					m = 0 ; n = 0 ;
				}
				else if(l == 1) {
					m = 1 ; n = 0 ;
				}
				else if(l == 2) {
					m = -1 ; n = 0 ;
				}
				else if(l == 3) {
					m = -0.5 , n = -1 ;
				}
				else if(l == 4) {
					m = 0.5 , n = -1 ;
				}
				else if(l == 5) {
					m = -0.5 ; n = 1 ;
				}
				else if(l == 6) {
					m = 0.5 ; n = 1 ;
				}
				exp_1.reset(proj_x + 20 * m , proj_y + 20 * n , 2) ;
				l++ ;
				for(int i = 0 ; i < 20 ; i++) {
					exp_1.scale(1.11) ;
					exp_1.setColor(COLOR(235 * (1.0 - i / 19.0) , 143 * (1.0 - i / 19.0) , 5 * (1.0 - i / 19.0)) , true) ;
					wait(0.005) ;
				}
				for(int i = 19 ; i >=0 ; i--) {
					exp_1.scale(1.0/1.11) ;
					exp_1.setColor(COLOR(235 * (1.0 - i / 19.0) , 143 * (1.0 - i / 19.0) , 5 * (1.0 - i / 19.0)) , true) ;
					wait(0.005) ;
				}
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 2.6 ;
		}
		//NAPALM
		else if(wpnactive2 == 24) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(237 , 185 , 3) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(237 * (1.0 - i / 24.0) , 185 * (1.0 - i / 24.0) , 3 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(237 * (1.0 - i / 24.0) , 185 * (1.0 - i / 24.0) , 3 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 1.6 ;
		}
		//JACK HAMMER
		else if(wpnactive2 == 25) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(64 , 0 , 0) , true) ;
			repeat(3) {
				for(int i = 0 ; i < 15 ; i++) {
					exp_1.scale(1.11) ;
					exp_1.setColor(COLOR(64 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
					wait(0.005) ;
				}
				for(int i = 14 ; i >=0 ; i--) {
					exp_1.scale(1.0/1.11) ;
					exp_1.setColor(COLOR(64 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0) , 0 * (1.0 - i / 14.0)) , true) ;
					wait(0.005) ;
				}
				exp_1.reset(proj_x , proj_y , 3) ;
				int i = 0 ;
				repeat(75) {
					exp_1.move(0 , -2 * (1.0 - i/75.0)) ;
					wait(0.01) ;
					i++ ;
				}
				i = 25 ;
				repeat(25) {
					exp_1.move(0 , 6 * (1.0 - i/25.0)) ;
					wait(0.008) ;
					i-- ;
				}
				exp_1.reset(proj_x , proj_y , 2) ;
			}		
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.5 ;
		}
		//HAIL STORM
		else if(wpnactive2 == 26) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(43 , 149 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(43 * (1.0 - i / 24.0) , 149 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(43 * (1.0 - i / 24.0) , 149 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 1.6 ;
		}
		//FLASH BLAST
		else if(wpnactive2 == 27) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(0 , 0 , 0) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				if(i % 2 == 0)
					exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
				else
					exp_1.setColor(COLOR(0 , 0 , 0) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				if(i % 2 == 0)
					exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
				else
					exp_1.setColor(COLOR(0 , 0 , 0) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.0 ;
			smultiplier = 0.6 ;
		}
		//SONIC BLAST
		else if(wpnactive2 == 28) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(3 , 103 , 252) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(3 * (1.0 - i / 24.0) , 103 * (1.0 - i / 24.0) , 252 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(3 * (1.0 - i / 24.0) , 103 * (1.0 - i / 24.0) , 252 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.1 ;
			smultiplier = 2.5 ;
		}
		//SUPER NOVA
		else if(wpnactive2 == 29) {
			exp_1.reset(proj_x , proj_y , 2) ;
			exp_1.setFill(true) ;
			exp_1.setColor(COLOR(255 , 255 , 255) , true) ;
			for(int i = 0 ; i < 25 ; i++) {
				exp_1.scale(1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			for(int i = 24 ; i >=0 ; i--) {
				exp_1.scale(1.0/1.11) ;
				exp_1.setColor(COLOR(255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0) , 255 * (1.0 - i / 24.0)) , true) ;
				wait(0.005) ;
			}
			exp_1.hide() ;
			dmultiplier = 1.2 ;
			smultiplier = 2.0 ;
		}
	}	
	if(overshoot == true)
		distance = 100 ;
	else if(hit == true)
		distance = 0 ;
	else
		distance = abs(proj_x - tanks1.x) ;
	
	if(distance <= 100 * dmultiplier)
		tanks2.score = tanks2.score + (100 * dmultiplier - distance) * smultiplier ;
	
	t_right.reset(980 , 20 , tanks2.score) ;
	t_right.setColor(COLOR(255 , 255 , 255) , true) ;
}
	Text quit(500 , 400 , "QUIT") ;
	Text repl(500 , 350 , "MAIN MENU") ;
	Text winner_game(500 , 300 , " ") ;
	Rectangle replb(500 , 350 , 10 + textWidth("MAIN MENU") , 10 + textHeight()) ;
	Rectangle quitb(500 , 400 , 10 + textWidth("QUIT") , 10 + textHeight()) ;
	if(tanks1.score > tanks2.score)
		winner_game.reset(500 , 300 , "PLAYER 1 WINS..") ;
	else if(tanks1.score < tanks2.score)
		winner_game.reset(500 , 300 , "PLAYER 2 WINS..") ;
	else
		winner_game.reset(500 , 300 , "GAME TIED..") ;
	while(true) {
		int jj = getClick() ;
		int jj_x = jj / 65536 ;
		int jj_y = jj % 65536 ;
		if(jj_x < 505 + textWidth("MAIN MENU") / 2 && jj_x > 495 - textWidth("MAIN MENU") / 2 && jj_y < 355 + textHeight() / 2 && jj_y > 345 - textHeight() / 2) {
			for(int k = 0 ; k < 10 ; k++) {
				tanks1.isused[k] = false ;
				tanks2.isused[k] = false ;
			}
			tanks1.score = 0 ;
			tanks2.score = 0 ;
			tanks1.x = 40 ;
			tanks1.y = 520 ;
			tanks2.x = 960 ;
			tanks2.y = 520 ;
			closeCanvas() ;
			break ;
		}
		else if(jj_x < 505 + textWidth("QUIT") / 2 && jj_x > 495 - textWidth("QUIT") / 2 && jj_y < 405 + textHeight() / 2 && jj_y > 395 - textHeight() / 2)
			return 0;
		else
			continue ;
	}
}
}
