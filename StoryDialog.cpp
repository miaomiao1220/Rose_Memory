#include <map>
#include <vector>
#include <QList>
#include <QString>
#include <StoryDialog.h>

QList<QString> StoryDialogC::AddDia(QString typ, QString pic, QString person, QString adds) {
        auto rets = QList<QString>
                {
                        typ,
                        pic,
                        person,
                        adds
                };
        return rets;
    }

    StoryDialogC::StoryDialogC() {
        //        开始 = 0
        Dialogs[0] = QList<QList<QString >>();
        Dialogs[0].push_back(AddDia("0", "00", "风儿", "飞鸟吟唱，微风习习；花蝶飞舞，草木葱茏"));
        Dialogs[0].push_back(AddDia("0", "00", "风儿", "现在是八月初八，空气中都是暑假的慵懒和燥热。"));
        Dialogs[0].push_back(AddDia("0", "00", "风儿", "枝头上摘了一根黄瓜，在嘴里咔嚓一声咬开。 \n清甜荡漾"));
        Dialogs[0].push_back(AddDia("0", "00", "风儿", "在郊区的度假的小木屋的后院，你舒服地躺在竹摇椅上。"));
        Dialogs[0].push_back(AddDia("0", "00", "风儿", "轻闭双眼，阳光匝泄，空气中飘来丝丝甜美的香味。"));
        Dialogs[0].push_back(AddDia("0", "00", "风儿", "这，是什么气味呢？"));

        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "南瓜转圈，......歌唱，葡萄......."));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "......草莓和西红柿手拉手......"));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "永远盛开......遗忘的乐园......"));

        Dialogs[0].push_back(AddDia("0", "00", "我", "是谁在说话？（从竹椅起身）"));
        Dialogs[0].push_back(AddDia("0", "00", "我", "（安安静静的后院，阳光倾泻）"));
        Dialogs[0].push_back(AddDia("0", "00", "我", "大概是幻听了吧。"));
        Dialogs[0].push_back(AddDia("0", "00", "我", "（看见一个破旧的 陶罐，蹲下去观察）"));
        Dialogs[0].push_back(AddDia("0", "00", "我", "啊啊（阳光突然亮得刺眼。）"));

        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "来吧，来吧"));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "誓言在泥土里沉睡"));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "播种、浇灌，等啊等，等啊等～"));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "五百二十个星星和一个月亮升起又落下，你就可以收获"));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "金色的许诺，唯一的承载"));
        Dialogs[0].push_back(AddDia("1", "20", "苍老的声音", "等待播种，第一个萝卜的故事"));

        //        萝卜 = 11
        Dialogs[11] = QList<QList<QString >>
                {
                        AddDia("0", "21", "羌",
                               "清炒胡萝卜丝、胡萝卜炒肉片。来！儿子，吃萝卜记性好的！"),
                        AddDia("1", "11", "儿子", "好吃，Umm，咔嚓咔嚓。"),
                        AddDia("1", "13", "儿子",
                               "为什么吃胡萝卜可以记性好呢？"),
                        AddDia("0", "24", "羌", "这个。。呃。。（思考中）"),
                        AddDia("0", "21", "羌", "（敷衍）因为胡萝卜是红色的。"),
                        AddDia("1", "11", "儿子",
                               "那是不是吃西红柿也会记性好啊？"),
                        AddDia("0", "21", "羌",
                               "是是是，快吃快吃！吃完赶紧去背课文！"),
                        AddDia("1", "12", "儿子", "（小声咕哝）呜，不想背。"),
                        AddDia("1", "11", "儿子",
                               "（我一根一根胡萝卜丝吃，慢点吃，就可以晚点背课文了。）")
                };

        //        白菜 = 12
        Dialogs[12] = QList<QList<QString >>
                {
                        AddDia("0", "14", "儿子", "吃不进去了，不想吃了啦！"),
                        AddDia("1", "21", "羌",
                               " 乖，吃完这一点点菜叶就给你加一个鸡腿。"),
                        AddDia("0", "12", "儿子", "不吃！"),
                        AddDia("1", "24", "羌",
                               " 妈妈以前最喜欢吃了，妈妈说过吃叶子菜长高高的。"),
                        AddDia("0", "14", "儿子", "那好吧，我吃掉，嗷呜。")
                };

        //         茄子 = 13
        Dialogs[13] = QList<QList<QString >>
                {
                        AddDia("1", "21", "羌",
                               "这个是早上刚从菜园子里摘的圆茄子。今晚给你炒老爸拿手的茄子烧肉，庆祝你考上了重点高中啊！"),
                        AddDia("0", "11", "儿子",
                               "圆茄子？看起来是大号的紫色西红柿。"),
                        AddDia("1", "21", "羌", "哈哈哈哈哈～别说真有点像。"),
                        AddDia("1", "23", "羌", "（如果她在，会喜欢圆茄子吗）")
                };

        //        番茄 = 14
        Dialogs[14] = QList<QList<QString >>
                {
                        AddDia("0", "11", "儿子",
                               "院子里面西红柿我摘了两，做凉拌的吧！"),
                        AddDia("1", "24", "羌",
                               "糖罐子在柜子第一层，自己拿吧。"),
                        AddDia("0", "11", "儿子", "咚咚咚，咚咚咚"),
                        AddDia("0", "11", "儿子",
                               "啊呜。今年的西红柿汁水真足。"),
                        AddDia("0", "11", "儿子",
                               "对啦爸，小时候你骗我红色的蔬果吃了可以背好课文。"),
                        AddDia("0", "11", "儿子",
                               "当时我告诉我喜欢的女孩儿，她一天十个西红柿吃坏肚子了。"),
                        AddDia("1", "22", "羌",
                               "你小子，小学就追女孩了？你现在啥时候带个姑娘回来？")
                };

        //        辣椒 = 15
        Dialogs[15] = QList<QList<QString >>
                {
                        AddDia("0", "21", "羌",
                               "喂，儿子啊，辣椒寄过来了，今年的辣椒可辣了！"),
                        AddDia("1", "10", "儿子",
                               "谢谢爸！是院子里种的辣椒吧！"),
                        AddDia("0", "21", "羌",
                               "哈哈哈是啊，今年悠着点吃啊。去年你还吃到拉肚子呢。"),
                        AddDia("1", "10", "儿子",
                               "嗯嗯，爸，您也多保重身体。我和妻子都好呢，明年接您过来一起住。")
                };

        //        南瓜 = 16
        Dialogs[16] = QList<QList<QString >>
                {
                        AddDia("0", "21", "羌",
                               "南瓜饼好咯！儿子小时候最喜欢吃南瓜饼啦。"),
                        AddDia("1", "00", "老友",
                               "你儿子学习好，去美国发展了啊。南瓜饼做了给他寄一点吧。"),
                        AddDia("1", "00", "老友",
                               "不过啊，这么久没回来过了，您老也叫他回来一次啊。"),
                        AddDia("0", "21", "羌",
                               "哈哈，是啊。他挺忙的，我让他别回来呢，好好工作。"),
                        AddDia("1", "00", "老友",
                               "哎呀，孩子回来还是挺好，下回不用劝了。\n走啦！"),
                        AddDia("0", "21", "羌", "您慢走！"),
                        AddDia("0", "23", "羌", "哎，给儿子供个南瓜饼吧。")
                };


        //        黄瓜 = 17,
        Dialogs[17] = QList<QList<QString >>
                {
                        AddDia("0", "21", "羌", "来吃点黄瓜。刚摘下来的。"),
                        AddDia("1", "10", "儿子",
                               "这小园子长的瓜果真不错，我从小吃到大啊～ \nkacha!"),
                        AddDia("0", "21", "羌",
                               "你还在肚子里面的时候，就在吃呢。"),
                        AddDia("1", "10", "儿子", "说起来，爸，你会有儿媳妇了！")
                };


        //        橘子 = 21,
        Dialogs[21] = QList<QList<QString >>
                {
                        AddDia("0", "24", "羌",
                               "橘子，要学会和别的小朋友分享。"),
                        AddDia("1", "12", "儿子",
                               "我一个人就可以吃掉一整个橘子！不要不要给别的小朋友！"),
                        AddDia("0", "24", "羌",
                               "儿子你看，橘子那么多片，就是为了方便人们互相分享的呀～"),
                        AddDia("0", "24", "羌",
                               "你不分享，橘子会难过，明天就藏起来，你就吃不到了哦。"),
                        AddDia("1", "14", "儿子", "那，给妈妈一半，我吃另一半")
                };

        //        蓝莓 = 22,
        Dialogs[22] = QList<QList<QString >>
                {
                        AddDia("0", "12", "儿子", "妈妈为什么还不回来呀。"),
                        AddDia("1", "24", "羌",
                               "妈妈工作很忙啦，这是妈妈寄给你的蓝莓。"),
                        AddDia("0", "12", "儿子",
                               "可是，幼儿园的老师说，过一次生日就是一年。妈妈走之后，我又过了两个生日啦。"),
                        AddDia("1", "24", "羌",
                               "妈妈，也会很想你吧。乖，吃掉蓝莓，妈妈会高兴的。"),
                        AddDia("0", "11", "儿子",
                               "妈妈说过，蓝莓会鼓掌。啊呜啊呜～"),
                        AddDia("1", "23", "羌", "（小声）哎～你要健健康康长大呀～")
                };

        //        草莓 = 23,
        Dialogs[23] = QList<QList<QString >>
                {
                        AddDia("0", "33", "薇薇",
                               "终于是过上安稳一点的生活了，买了你喜欢的草莓。"),
                        AddDia("1", "00", "羌",
                               "哎呀，买这么多干什么！我肯定吃不完呀，你又不喜欢吃草莓。"),
                        AddDia("0", "33", "薇薇",
                               "不浪费的～不浪费的～我知道你肯定吃得完。不要对自己太省啦！"),
                        AddDia("0", "33", "薇薇",
                               "因为我不喜欢，你都多久没吃过草莓啦。")
                };

        //        香蕉 = 24,
        Dialogs[24] = QList<QList<QString >>
                {
                        AddDia("0", "33", "羌",
                               "又是香蕉，因为是最便宜的水果啦。"),
                        AddDia("1", "00", "薇薇", "好吃的好吃的！！"),
                        AddDia("0", "34", "羌",
                               "我们会过上好日子的。刚参加工作，一切只能节省点儿。"),
                        AddDia("1", "00", "薇薇",
                               "嗯嗯！今年目标存上二十万！而且，香蕉真的很好吃呀！")
                };

        //        石榴 = 25,
        Dialogs[25] = QList<QList<QString >>
                {
                        AddDia("0", "33", "羌",
                               "有人送了我们一箱子石榴。我尝了半个，特别酸。"),
                        AddDia("1", "00", "薇薇",
                               "诶诶！我就想吃酸的，特别想吃酸的！"),
                        AddDia("0", "33", "羌",
                               "辣女儿酸儿子，你怀的是不是个儿子呀哈哈哈！给你给你！"),
                        AddDia("1", "00", "薇薇",
                               "好吃啊，你在后院里面也种一棵吧！我爱吃。"),
                        AddDia("1", "00", "薇薇",
                               "一到夏天，就能听石榴树唱歌了～")
                };

        //        茉莉 = 31,
        Dialogs[31] = QList<QList<QString >>
                {
                        AddDia("0", "32", "薇薇",
                               "我家种的茉莉花开了，晒了点泡茶。给你也带了点！"),
                        AddDia("1", "00", "羌",
                               "谢谢，但是我不喜欢花茶，所以你还是拿回去吧。"),
                        AddDia("0", "32", "薇薇",
                               "（很生气但忍住了）你可以拿回去给你妈妈喝。"),
                        AddDia("1", "00", "羌",
                               "我，我没有妈妈。薇薇，我是和外婆一起长大的。"),
                        AddDia("0", "32", "薇薇",
                               "这样啊，其实，我也没有妈妈，我是和外公一起长大的。")
                };

        //        芝樱 = 32,
        Dialogs[32] = QList<QList<QString >>
                {
                        AddDia("0", "33", "羌", "情，情人节快乐！（拿出花束）"),
                        AddDia("1", "00", "薇薇",
                               "诶！！这是，这是什么花？粉色的，好可爱。"),
                        AddDia("0", "33", "羌",
                               "是芝樱花。是代表希望。祝我们有美好的未来。"),
                        AddDia("1", "00", "薇薇",
                               "谢谢你！话说，你知道我最喜欢什么花吗？"),
                        AddDia("1", "00", "薇薇",
                               "哈哈羌哥，我们两名字连起来是什么呢？你看，这旁边，都是蔷薇"),
                        AddDia("0", "33", "羌",
                               "蔷薇？这个是小野花，不是蔷薇啦！"),
                        AddDia("1", "00", "薇薇",
                               "我不管我不管啦！就是最喜欢这个花，这就是我心里面的金蔷薇！"),
                        AddDia("1", "00", "薇薇",
                               "我也给你准备了礼物哦～一会拿给你！")
                };

        //        葡萄风信子 = 33,
        Dialogs[33] = QList<QList<QString >>
                {
                        AddDia("0", "33", "羌",
                               "薇薇，你看这个花，圆圆的一大坨。"),
                        AddDia("1", "00", "薇薇", "哈哈！好可爱啊！"),
                        AddDia("1", "00", "薇薇",
                               "话说羌哥，你都跟着我好多天了，当我看不见吗！"),
                        AddDia("0", "33", "羌",
                               "我回家也是走这条路，怎么就跟着你了。而且这个长得很像葡萄的花，真的很好看啊，我就是想路过看看。"),
                        AddDia("1", "00", "薇薇",
                               "哦～那我每次在家里的窗子看见你往回走好远呢，是我眼花了～"),
                        AddDia("0", "33", "羌", "我，我，我家在前面一点点！"),
                        AddDia("1", "00", "薇薇",
                               "原来你是偏爱看葡萄风信子呀～"),
                        AddDia("0", "33", "羌", "不是。。是。。是。。"),
                        AddDia("0", "33", "羌", "（非常小声）是偏爱看你"),
                        AddDia("1", "00", "风儿",
                               "画面仿佛静止了。少女的脸颊格外红润。\n和葡萄风信子一起荡漾在初春的悸动中。")
                };
    }

StoryDialogC StoryDialog;
