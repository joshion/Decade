#! https://zhuanlan.zhihu.com/p/402463649

# Preface

> 事情开始总是困难的，但事情总是要开始的。

看了《射雕英雄传》、《剑玄录》和《紫电青霜》等武侠小说后，我一度梦想成为武侠小说家。而接近二十年后的今天，我是一名码农，似乎已经远梦想太远太远。但深究一下，两者又何其相似？当今，写手已不在用笔刻着字而是坐在电脑前敲着键盘，而码农也是坐在电脑前敲着键盘；写手得先明确主题列出大纲然后逐步扩展细节，而码农也是选对方向搭起框架然后逐步添加业务逻辑。原来，殊途同归。

如果这是一个小说系列，这章的题目就应为“Prologue”，那么我就可以搞点散文，随便瞎写点什么“形散神不散”的东西。然而，这是一个系列教学，我只能言归正传，聊聊为什么想和会开这个专栏。

十年前的暑假，在一次朋友聚会中，翻开了《C++程序设计》，学会了“编程”这个名词。一年后，我上了大学，选择的是“计算机科学与技术”这个专业。再一次年后，也就是一四年，在那个暑假跟随了隔壁兄弟学院————自动化学院的导师和博士生参与了广船的一个三维建模项目。虽然由于个人技术太烂很快就被抛弃，但是在那段时间里学习了《OpenGL编程指南-第三版》并使用C语言编程绘制了Bézier曲面。随后，也应用OpenGL1.0编写程序完成了数据结构课程设计————《夜降彩色雨》。如今，翻看起那些代码，不禁嘲笑当初稚嫩的自己，但当年能够做出一个能跑起来的程序，真是巨大的成就感啊。

```c++
  // 设置涟漪颜色
  glColor4f(m_pRain->m_vRipple[i]->r, m_pRain->m_vRipple[i]->g,
            m_pRain->m_vRipple[i]->b, m_pRain->m_vRipple[i]->life);
  glPushMatrix();
  glTranslatef(x, 0, z);
  glBegin(GL_POINTS);
  const float Pi = 3.1415926536f;
  const int n = 200;
  for(int i = 0; i < n; ++i)
  {
    glVertex3f(radius * 3/4 * cos(2*Pi/n*i), 0 , radius * 3/4 * sin(2*Pi/n*i));
    glVertex3f(radius * cos(2*Pi/n*i), 0 , radius * sin(2*Pi/n*i));
  }
  glEnd();
  glPopMatrix();
```

![Image](https://pic4.zhimg.com/80/v2-c1de5eb204e433932b6ca33233f6ed27.png)

再往后的几年，接触了各种各样的软件领域：大数据、网站、人脸识别、车载设备和智能家居等等。最终，机缘巧合下进入了CAD这个行业，回到了最初的“三维建模”软件。但这一次，知道了Nurbs，了解了参数化建模，参与了产品研发。在从事这个行业的生涯里，也更深刻地理解软件工程，从产品定义，研发，测试，集成，发布等各个环节充分地参与了软件产品的整个生命周期，领悟了软件工程和科学研究的差异。这些经历经验是一份宝贵的财富，也是我所想分享给后来者的。因此，有了这么一个专题————《Develop a CAD》，以及伴随这个专栏的《[Decade](https://github.com/joshion/Decade)》。
