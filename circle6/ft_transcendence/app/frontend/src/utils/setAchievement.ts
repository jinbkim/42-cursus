/*!
 * @author donglee
 * @brief ledder_level �� ���� achievement Īȣ ��ȯ
 */
export const setAchievementStr = (ledder_level: number): string => {
	if (ledder_level < 500) {
		return "not human";
	} else if (ledder_level >= 500 && ledder_level < 1000) {
		return "bronze";
	} else if (ledder_level >= 1000 && ledder_level < 1500) {
		return "silver";
	} else if (ledder_level >= 1500) {
		return "gold";
	}
};

/*!
 * @author donglee
 * @brief ledder_level �� ���� achievement �̹������ ��ȯ
 */
export const setAchievementImg = (ledder_level: number): string => {
	if (ledder_level < 500) {
		return "/public/crown.png";
	} else if (ledder_level >= 500 && ledder_level < 1000) {
		return "/public/green-crown.png";
	} else if (ledder_level >= 1000 && ledder_level < 1500) {
		return "/public/yellow-crown.png";
	} else if (ledder_level >= 1500) {
		return "/public/red-crown.png";
	}
};